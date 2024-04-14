// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/S_RUN.h"
#include "CCharacterPlayer.h"
#include "FSM_Collection.h"
#include "GameFramework\CharacterMovementComponent.h"


IIPlayerState* S_RUN::updateInput(ACCharacterPlayer& player)
{
	if (player.getPlayerController()->WasInputKeyJustReleased(EKeys::LeftShift))
	{
		return new S_WALK();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::SpaceBar))
	{
		return new JUMP();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::R))
	{
		player.Draw();
		return new DRAWING();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftControl))
	{
		FVector2D movementVector = player.GetMoveInputActionValue().Get<FVector2D>();
		FName temp;
		if (movementVector.X >= 0)
			temp = FName("Front");
		if (movementVector.X < 0)
			temp = FName("Back");
		if (movementVector.Y < 0)
			temp = FName("Left");
		if (movementVector.Y > 0)
			temp = FName("Right");
		return new S_ROLL(temp);
	}
	return NULL;
}

void S_RUN::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());

	//set this enter
	player.Move(player.GetMoveInputActionValue());
	return;
}

void S_RUN::enter(ACCharacterPlayer& player)
{
	player.GetCharacterMovement()->MaxWalkSpeed = 1000;
}

void S_RUN::exit(ACCharacterPlayer& player)
{
	player.GetCharacterMovement()->MaxWalkSpeed = 1000 / 2.0f;
}

void S_RUN::Destroy()
{
	delete this;
}
