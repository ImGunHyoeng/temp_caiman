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
	PrimaryActorTick.bCanEverTick = true;

}

//TScriptInterface<IIPlayerState> ASHEATHING_A::updateInput(ACCharacterPlayer& player)
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
	if (ctx->GetWaitFrame() <= 0)
	{
		SwitchState(factory->CreateS_IDLE());
	}
	if (ctx->GetMoveInputActionValue().GetMagnitude() > 0.1f && ctx->GetWaitFrame() <= 6)
	{
		ctx->StopAnimMontage(ctx->GetSheathMontage());
		ctx->SetWaitFrame(0);
		SwitchState(factory->CreateS_IDLE());
	}
}

void ASHEATHING_A::update()
{
	ctx->Look(ctx->GetLookInputActionValue());
	ctx->WaitFramePassing(); 
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
	ctx->SetWaitFrame(8);
}

void ASHEATHING_A::exit()
{
}

void ASHEATHING_A::InitializeSubState()
{

}

void ASHEATHING_A::Destroy()
{
	this->MarkPendingKill();
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

