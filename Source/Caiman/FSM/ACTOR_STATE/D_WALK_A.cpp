// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/D_WALK_A.h"
#include "AFSMCollection.h"
#include "CCharacterPlayer.h"
#include "CMyWeapon.h"
#include "GameFramework/CharacterMovementComponent.h"
// Sets default values
AD_WALK_A::AD_WALK_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

//IIPlayerState* AD_WALK_A::updateInput(ACCharacterPlayer& player)
//{
//	if (player.GetMoveInputActionValue().GetMagnitude() < 0.1f)
//	{
//
//		return NewObject<AD_IDLE_A>();
//	}
//	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftMouseButton))
//	{
//		player.SetWaitFrame(70);
//		return NewObject<AATTACK_A>();
//	}
//	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::R))
//	{
//		player.Sheath();
//		return NewObject<ASHEATHING_A>();
//	}	
//	return nullptr;
//}

void AD_WALK_A::updateInput()
{
	if (ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::Q))
	{
		ctx->GetCurPlayerState()->SwitchState(factory->CreateINVINCIBILITY());
		return;
	}
	if (ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::LeftControl))
	{
		ctx->StopMove();
		ctx->GetCurPlayerState()->SwitchState(factory->CreateINVINCIBILITY());
		return;
	}
	if (ctx->GetMoveInputActionValue().GetMagnitude() < 0.1f)
	{
		SwitchState(factory->CreateD_IDLE());
	}
	if (ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::LeftMouseButton))
	{
		//ctx->SetWaitFrame(70);
		SwitchState(factory->CreateATTACK());
	}
	if (ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::R))
	{
		ctx->Sheath();
		SwitchState(factory->CreateSHEATHING());
	}
}

void AD_WALK_A::update()
{
	ctx->Move(ctx->GetMoveInputActionValue());
	ctx->Look(ctx->GetLookInputActionValue());
	updateInput();

}

//void AD_WALK_A::update(ACCharacterPlayer& player)
//{
//	player.Move(player.GetMoveInputActionValue());
//	player.Look(player.GetLookInputActionValue());
//}

void AD_WALK_A::enter()
{
	ctx->GetCharacterMovement()->MaxWalkSpeed = 1000 / 3.0f;
}

void AD_WALK_A::exit()
{
}

void AD_WALK_A::Destroy()
{
	//this->MarkPendingKill();
}

void AD_WALK_A::InitializeSubState()
{
}

// Called when the game starts or when spawned
void AD_WALK_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AD_WALK_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

