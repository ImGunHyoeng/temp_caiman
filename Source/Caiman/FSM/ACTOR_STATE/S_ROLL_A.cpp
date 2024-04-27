// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/S_ROLL_A.h"
#include "AnimInstance\KwangAnimInstance.h"
#include "CCharacterPlayer.h"
#include "AFSMCollection.h"
#include "FSM/PlayerStateFactory.h"
// Sets default values
AS_ROLL_A::AS_ROLL_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	 isRoll = true;
}

//TScriptInterface<IIPlayerState> AS_ROLL_A::updateInput(ACCharacterPlayer& player)
//{
//	if (player.GetWaitFrame() < 0)
//	{
//		return NewObject<AS_IDLE_A>();
//		player.StopAnimMontage();
//	}
//	return nullptr;
//}

void AS_ROLL_A::updateInput()
{
	if (end)
	{
		ctx->StopAnimMontage();
		ctx->GetCurPlayerState()->SwitchState(factory->CreateNORMAL());
		return;
	}
}

void AS_ROLL_A::update()
{
	//ctx->Move(ctx->GetMoveInputActionValue());
	if (isRoll)
		ctx->AddMovementInput(ctx->GetActorForwardVector(), 5);
	ctx->Look(ctx->GetLookInputActionValue());
	updateInput();
}

//void AS_ROLL_A::update(ACCharacterPlayer& player)
//{
//	player.WaitFramePassing();
//	//player.Move(player.GetMoveInputActionValue());
//	if (isRoll)
//		player.AddMovementInput(player.GetActorForwardVector(), 3);
//	//if (!isRoll)
//	//	player.SetWaitFrame(4);
//	player.Look(player.GetLookInputActionValue());
//}

void AS_ROLL_A::enter()
{
	kwang = ctx->getAnimInstance();
	isRoll = true;
	ctx->PlayAnimMontage(ctx->GetRollMontage(), 1.0f, input);
	end = false;
}

void AS_ROLL_A::exit()
{
	isRoll = true;
	end = false;
}

void AS_ROLL_A::Destroy()
{
	//this->MarkPendingKill();
}

void AS_ROLL_A::InitializeSubState()
{
}

// Called when the game starts or when spawned
void AS_ROLL_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AS_ROLL_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

