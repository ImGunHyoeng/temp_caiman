// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/ATTACK_A.h"
#include "CCharacterPlayer.h"
#include "AFSMCollection.h"
#include "FSM/PlayerStateFactory.h"
// Sets default values
AATTACK_A::AATTACK_A(ACCharacterPlayer* _ctx, PlayerStateFactory* _factory):IIPlayerState(_ctx,_factory)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

TScriptInterface<IIPlayerState> AATTACK_A::updateInput(ACCharacterPlayer& player)
{
	if (changeCharge)
	{
		//player.StopAnimMontage();
		player.PlayAnimMontage(player.GetChargeAttackMontage(), 1.0f,FName("ChargingStart"));
		return NewObject<ACHARGINGATTACK_A>();
		SwitchState(factory->CreateCHARGINGATTACK());
	}
	if (curAttackState == EAttackState::END)
	{
		ctx->StopAnimMontage();
		player.StopAnimMontage();
		return NewObject<AD_IDLE_A>();
	}
	return nullptr;
}

void AATTACK_A::updateInput()
{
}

void AATTACK_A::update()
{
}

void AATTACK_A::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
	//DoingTime+=FApp::GetDeltaTime()*60;
	//if (player.getPlayerController()->WasInputKeyJustReleased(EKeys::LeftMouseButton))
	//	DoingTime = 0;

	
	if (curAttackState == EAttackState::DONE)
	{
		if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftMouseButton))
		{
			curAttackState = EAttackState::DOING;
			//DoingTime = 100;
			//player.SetWaitFrame(60);
			player.PlayAnimMontage(player.GetAttackMontage(), 1.0f, "Attack_2_2");
		}
	}
}

void AATTACK_A::enter(ACCharacterPlayer& player)
{
	//DoingTime = 0;
	curAttackState = EAttackState::DOING;
	player.PlayAnimMontage(player.GetAttackMontage(), 1.0f, "Attack_2_1");
	changeCharge = false;
}

void AATTACK_A::exit(ACCharacterPlayer& player)
{
}

void AATTACK_A::Destroy()
{
}

void AATTACK_A::InitializeSubState()
{
}

void AATTACK_A::ChangeChargeAttack()
{
	changeCharge = true;
}

// Called when the game starts or when spawned
void AATTACK_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AATTACK_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

