// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/JUMPATTACK_A.h"
#include "AFSMCollection.h"
#include "CCharacterPlayer.h"
#include "CMyWeapon.h"
#include "AnimInstance\KwangAnimInstance.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
AJUMPATTACK_A::AJUMPATTACK_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

TScriptInterface<IIPlayerState> AJUMPATTACK_A::updateInput(ACCharacterPlayer& player)
{
	if (player.GetWaitFrame() <= 0)
	{
		if (kwang)
			kwang->setJumpAttackEnd();
		return NewObject<AD_IDLE_A>();
	}
	return nullptr;
}

void AJUMPATTACK_A::updateInput()
{
	if (ctx->GetWaitFrame() <= 0)
	{
		if (kwang)
			kwang->setJumpAttackEnd();
		SwitchState(factory->CreateD_IDLE());
	}
}

void AJUMPATTACK_A::update()
{
	ctx->Look(ctx->GetLookInputActionValue());
	ctx->WaitFramePassing();
	updateInput();

}

void AJUMPATTACK_A::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
	player.WaitFramePassing();
}

void AJUMPATTACK_A::enter(ACCharacterPlayer& player)
{
	kwang = player.getAnimInstance();
	if (kwang)
	{
		kwang->setDraw();
		kwang->setJumpAttack();
	}
}

void AJUMPATTACK_A::exit(ACCharacterPlayer& player)
{
}

void AJUMPATTACK_A::Destroy()
{
	this->MarkPendingKill();
}

void AJUMPATTACK_A::InitializeSubState()
{
}

// Called when the game starts or when spawned
void AJUMPATTACK_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJUMPATTACK_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

