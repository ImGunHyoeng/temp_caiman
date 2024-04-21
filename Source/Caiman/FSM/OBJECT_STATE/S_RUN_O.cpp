// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/OBJECT_STATE/S_RUN_O.h"
#include "CCharacterPlayer.h"
#include "GameFramework\CharacterMovementComponent.h"
#include "OFSMCollection.h"

TScriptInterface<IIPlayerState> US_RUN_O::updateInput(ACCharacterPlayer& player)
{
	if (player.getPlayerController()->WasInputKeyJustReleased(EKeys::LeftShift))
	{
		return NewObject<US_WALK_O>();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::SpaceBar))
	{
		return NewObject<UJUMP_O>();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::R))
	{
		player.Draw();
		return NewObject<UDRAWING_O>();
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
		return NewObject<US_ROLL_O>();
	}
	return nullptr;
}

void US_RUN_O::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());

	//set this enter
	player.Move(player.GetMoveInputActionValue());
}

void US_RUN_O::enter(ACCharacterPlayer& player)
{
	player.GetCharacterMovement()->MaxWalkSpeed = 1000;
}

void US_RUN_O::exit(ACCharacterPlayer& player)
{
	player.GetCharacterMovement()->MaxWalkSpeed = 1000 / 2.0f;
}

void US_RUN_O::Destroy()
{
	this->MarkPendingKill();
}
