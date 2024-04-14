// Fill out your copyright notice in the Description page of Project Settings.


#include "S_WALK.h"
#include "CCharacterPlayer.h"
#include "FSM_Collection.h"
#include "GameFramework/CharacterMovementComponent.h"


IIPlayerState * S_WALK::updateInput(ACCharacterPlayer& player)
{
	if (player.getPlayerController()->IsInputKeyDown(EKeys::LeftShift))
	{
		return new S_RUN();
	}
	if (player.GetMoveInputActionValue().GetMagnitude() < 0.1f)
	{
		return new S_IDLE();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::R))
	{
		player.Draw();
		return new DRAWING();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::SpaceBar))
	{
		return new JUMP();
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

void S_WALK::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
	player.Move(player.GetMoveInputActionValue());
}

void S_WALK::enter(ACCharacterPlayer& player)
{
	player.GetCharacterMovement()->MaxWalkSpeed = 1000 / 2.0f;
}

void S_WALK::exit(ACCharacterPlayer& player)
{
}

void S_WALK::Destroy()
{
	delete this;
}
