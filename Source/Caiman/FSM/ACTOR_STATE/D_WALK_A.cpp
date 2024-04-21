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
	PrimaryActorTick.bCanEverTick = true;

}

TScriptInterface<IIPlayerState> AD_WALK_A::updateInput(ACCharacterPlayer& player)
{
	if (player.GetMoveInputActionValue().GetMagnitude() < 0.1f)
	{

		return NewObject<AD_IDLE_A>();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftMouseButton))
	{
		player.SetWaitFrame(70);
		return NewObject<AATTACK_A>();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::R))
	{
		player.Sheath();
		return NewObject<ASHEATHING_A>();
	}	
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftControl))
	{
		player.StopMove();
		player.NoAnimSheath();
		return NewObject<AS_ROLL_A>();
	}
	return nullptr;
}

void AD_WALK_A::update(ACCharacterPlayer& player)
{
	player.Move(player.GetMoveInputActionValue());
	player.Look(player.GetLookInputActionValue());
}

void AD_WALK_A::enter(ACCharacterPlayer& player)
{
	player.GetCharacterMovement()->MaxWalkSpeed = 1000 / 3.0f;
}

void AD_WALK_A::exit(ACCharacterPlayer& player)
{
}

void AD_WALK_A::Destroy()
{
	this->MarkPendingKill();
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

