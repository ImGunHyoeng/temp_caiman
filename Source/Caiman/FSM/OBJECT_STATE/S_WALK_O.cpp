// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/OBJECT_STATE/S_WALK_O.h"
#include "CCharacterPlayer.h"
#include "OFSMCollection.h"
#include "GameFramework/CharacterMovementComponent.h"

TScriptInterface<IIPlayerState> US_WALK_O::updateInput(ACCharacterPlayer& player)
{
	if (player.getPlayerController()->IsInputKeyDown(EKeys::LeftShift))
	{
		return NewObject<US_RUN_O>();
	}
	if (player.GetMoveInputActionValue().GetMagnitude() < 0.1f)
	{
		return NewObject<US_IDLE_O>();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::R))
	{
		player.Draw();
		return NewObject<UDRAWING_O>();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::SpaceBar))
	{
		return NewObject<UJUMP_O>();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftControl))
	{
		player.StopMove();
		return NewObject<US_ROLL_O>();
	}
    return nullptr;
}

void US_WALK_O::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
	player.Move(player.GetMoveInputActionValue());
}

void US_WALK_O::enter(ACCharacterPlayer& player)
{
	player.GetCharacterMovement()->MaxWalkSpeed = 1000 / 2.0f;
}

void US_WALK_O::exit(ACCharacterPlayer& player)
{
}

void US_WALK_O::Destroy()
{
	this->MarkPendingKill();
}
