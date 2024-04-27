// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/S_IDLE_A.h"
#include "AFSMCollection.h"
#include "CCharacterPlayer.h"
#include "CMyWeapon.h"
#include "AnimInstance\KwangAnimInstance.h"
#include "FSM/PlayerStateFactory.h"
// Sets default values
AS_IDLE_A::AS_IDLE_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

//TScriptInterface<IIPlayerState> AS_IDLE_A::updateInput(ACCharacterPlayer& player)
//{
//	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::SpaceBar))
//	{
//		return NewObject<AJUMP_A>();
//	}
//	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::R))
//	{
//		player.Draw();
//		return NewObject<ADRAWING_A>();
//	}
//	if (player.GetMoveInputActionValue().GetMagnitude() > 0.1f)
//	{
//		return NewObject<AS_WALK_A>();
//	}
//	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftControl))
//	{
//		player.StopMove();
//		return NewObject<AS_ROLL_A>();
//	}
//	return nullptr;
//}

void AS_IDLE_A::updateInput()
{
	if (ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::LeftControl))
	{
		ctx->StopMove();
		ctx->GetCurPlayerState()->SwitchState(factory->CreateINVINCIBILITY());
		return;
	}
	if (ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::SpaceBar))
	{
		SwitchState(factory->CreateJUMP());
		return;
	}
	if (ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::R))
	{
		ctx->Draw();
		SwitchState(factory->CreateDRAWING());
		return;
	}
	if (ctx->GetMoveInputActionValue().GetMagnitude() > 0.1f)
	{
		SwitchState(factory->CreateS_WALK());
		return;
	}
	
}

void AS_IDLE_A::update()
{
	ctx->Look(ctx->GetLookInputActionValue());
	updateInput();
}

//void AS_IDLE_A::update(ACCharacterPlayer& player)
//{
//	player.Look(player.GetLookInputActionValue());
//	updateInput();
//}

void AS_IDLE_A::enter()
{
	kwang = ctx->getAnimInstance();
	if (kwang)
		kwang->setSheath();
}

void AS_IDLE_A::exit()
{
}

void AS_IDLE_A::Destroy()
{
	//this->MarkPendingKill();
}

void AS_IDLE_A::InitializeSubState()
{
}

// Called when the game starts or when spawned
void AS_IDLE_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AS_IDLE_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

