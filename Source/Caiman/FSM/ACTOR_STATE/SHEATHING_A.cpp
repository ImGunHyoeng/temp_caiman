// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/SHEATHING_A.h"
#include "AFSMCollection.h"
#include "CCharacterPlayer.h"
#include "Animation/AnimInstance.h"
#include "FSM/PlayerStateFactory.h"

// Sets default values
ASHEATHING_A::ASHEATHING_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

//IIPlayerState* ASHEATHING_A::updateInput(ACCharacterPlayer& player)
//{
//	if (player.GetWaitFrame() <= 0)
//	{
//		return NewObject<AS_IDLE_A>();
//	}
//	if (player.GetMoveInputActionValue().GetMagnitude() > 0.1f && player.GetWaitFrame() <= 6)
//	{
//		player.StopAnimMontage(player.GetSheathMontage());
//		player.SetWaitFrame(0);
//		return NewObject<AS_IDLE_A>();
//	}
//	return nullptr;
//}

void ASHEATHING_A::updateInput()
{
	if (end)
	{
		SwitchState(factory->CreateS_IDLE());
	}
	if (ctx->GetMoveInputActionValue().GetMagnitude() > 0.1f && canChange)
	{
		ctx->StopAnimMontage(ctx->GetSheathMontage());
		SwitchState(factory->CreateS_IDLE());
	}
}

void ASHEATHING_A::update()
{
	ctx->Look(ctx->GetLookInputActionValue());
	updateInput();
}

//void ASHEATHING_A::update(ACCharacterPlayer& player)
//{
//	player.Look(player.GetLookInputActionValue());
//	player.WaitFramePassing();
//}

void ASHEATHING_A::enter()
{
	ctx->SetSheath(true);
	canChange = false;
	end = false;
}

void ASHEATHING_A::exit()
{
	canChange = false;
	end = false;
}

void ASHEATHING_A::InitializeSubState()
{

}

void ASHEATHING_A::Destroy()
{
	//this->MarkPendingKill();
}

// Called when the game starts or when spawned
void ASHEATHING_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASHEATHING_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

