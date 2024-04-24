// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/JUMP_A.h"
#include "CCharacterPlayer.h"
#include "AFSMCollection.h"
#include "GameFramework\CharacterMovementComponent.h"
#include "AnimInstance/KwangAnimInstance.h"
// Sets default values
AJUMP_A::AJUMP_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

TScriptInterface<IIPlayerState> AJUMP_A::updateInput(ACCharacterPlayer& player)
{
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftMouseButton))
	{
		player.NoAnimDraw();
		player.SetWaitFrame(6);
		return NewObject<AJUMPATTACK_A>();
	}
	if (!(player.GetCharacterMovement()->IsFalling()))
	{
		return NewObject<AGROUNDED_A>();
	}
	return nullptr;
}

void AJUMP_A::updateInput()
{
}

void AJUMP_A::update()
{
}

void AJUMP_A::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
}

void AJUMP_A::enter(ACCharacterPlayer& player)
{
	kwang = player.getAnimInstance();
	if (kwang)
		kwang->setJump();
	player.Super::Jump();
}

void AJUMP_A::exit(ACCharacterPlayer& player)
{
	if (kwang)
		kwang->setJumpEnd();
}

void AJUMP_A::Destroy()
{
	this->MarkPendingKill();
}

void AJUMP_A::InitializeSubState()
{
}

// Called when the game starts or when spawned
void AJUMP_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJUMP_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

