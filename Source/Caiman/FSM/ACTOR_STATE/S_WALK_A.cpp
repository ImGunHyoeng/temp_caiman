// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/S_WALK_A.h"
#include "CCharacterPlayer.h"
#include "AFSMCollection.h"
#include "GameFramework/CharacterMovementComponent.h"
// Sets default values
AS_WALK_A::AS_WALK_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

TScriptInterface<IIPlayerState> AS_WALK_A::updateInput(ACCharacterPlayer& player)
{
	if (player.getPlayerController()->IsInputKeyDown(EKeys::LeftShift))
	{
		return NewObject<AS_RUN_A>();
	}
	if (player.GetMoveInputActionValue().GetMagnitude() < 0.1f)
	{
		return NewObject<AS_IDLE_A>();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::R))
	{
		player.Draw();
		return NewObject<ADRAWING_A>();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::SpaceBar))
	{
		return NewObject<AJUMP_A>();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftControl))
	{
		player.StopMove();
		return NewObject<AS_ROLL_A>();
	}
	return nullptr;
}

void AS_WALK_A::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
	player.Move(player.GetMoveInputActionValue());
}

void AS_WALK_A::enter(ACCharacterPlayer& player)
{
	player.GetCharacterMovement()->MaxWalkSpeed = 1000 / 2.0f;
}

void AS_WALK_A::exit(ACCharacterPlayer& player)
{
}

void AS_WALK_A::Destroy()
{
	this->MarkPendingKill();
}

// Called when the game starts or when spawned
void AS_WALK_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AS_WALK_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
