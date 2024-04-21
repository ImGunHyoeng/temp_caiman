// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/OBJECT_STATE/D_WALK_O.h"
#include "OFSMCollection.h"
#include "CCharacterPlayer.h"
#include "CMyWeapon.h"
#include "GameFramework/CharacterMovementComponent.h"

TScriptInterface<IIPlayerState> UD_WALK_O::updateInput(ACCharacterPlayer& player)
{
	if (player.GetMoveInputActionValue().GetMagnitude() < 0.1f)
	{

		return NewObject<UD_IDLE_O>();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftMouseButton))
	{
		player.SetWaitFrame(70);
		return NewObject<UATTACK_O>();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::R))
	{
		player.Sheath();
		return NewObject<USHEATHING_O>();
	}
	return nullptr;
}

void UD_WALK_O::update(ACCharacterPlayer& player)
{
	player.Move(player.GetMoveInputActionValue());
	player.Look(player.GetLookInputActionValue());
}

void UD_WALK_O::enter(ACCharacterPlayer& player)
{
	player.GetCharacterMovement()->MaxWalkSpeed = 1000 / 3.0f;
}

void UD_WALK_O::exit(ACCharacterPlayer& player)
{
}

void UD_WALK_O::Destroy()
{
	this->MarkPendingKill();
}
