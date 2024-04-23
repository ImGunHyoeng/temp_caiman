// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/S_RUN_A.h"
#include "CCharacterPlayer.h"
#include "GameFramework\CharacterMovementComponent.h"
#include "AFSMCollection.h"
// Sets default values
AS_RUN_A::AS_RUN_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

TScriptInterface<IIPlayerState> AS_RUN_A::updateInput(ACCharacterPlayer& player)
{
	if (player.getPlayerController()->WasInputKeyJustReleased(EKeys::LeftShift))
	{
		return NewObject<AS_WALK_A>();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::SpaceBar))
	{
		return NewObject<AJUMP_A>();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::R))
	{
		player.Draw();
		return NewObject<ADRAWING_A>();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftControl))
	{
		//FVector2D movementVector = player.GetMoveInputActionValue().Get<FVector2D>();
		//FName temp;
		//if (movementVector.X >= 0)
		//	temp = FName("Front");
		//if (movementVector.X < 0)
		//	temp = FName("Back");
		//if (movementVector.Y < 0)
		//	temp = FName("Left");
		//if (movementVector.Y > 0)
		//	temp = FName("Right");
		player.StopMove();
		return NewObject<AS_ROLL_A>();
	}
	return nullptr;
}

void AS_RUN_A::updateInput()
{
}

void AS_RUN_A::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());

	//set this enter
	player.Move(player.GetMoveInputActionValue());
}

void AS_RUN_A::enter(ACCharacterPlayer& player)
{
	player.GetCharacterMovement()->MaxWalkSpeed = 1000;
}

void AS_RUN_A::exit(ACCharacterPlayer& player)
{
	player.GetCharacterMovement()->MaxWalkSpeed = 1000 / 2.0f;
}

void AS_RUN_A::Destroy()
{
	this->MarkPendingKill();
}

// Called when the game starts or when spawned
void AS_RUN_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AS_RUN_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

