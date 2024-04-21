// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/ATTACK_A.h"
#include "CCharacterPlayer.h"
#include "AFSMCollection.h"
// Sets default values
AATTACK_A::AATTACK_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

TScriptInterface<IIPlayerState> AATTACK_A::updateInput(ACCharacterPlayer& player)
{
	if (curAttackState == EAttackState::END)
	{
		player.StopAnimMontage();
		return NewObject<AD_IDLE_A>();
	}
	return nullptr;
}

void AATTACK_A::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());

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
	//DoingTime = 30;
	curAttackState = EAttackState::DOING;
	player.PlayAnimMontage(player.GetAttackMontage(), 1.0f, "Attack_2_1");
}

void AATTACK_A::exit(ACCharacterPlayer& player)
{
}

void AATTACK_A::Destroy()
{
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

