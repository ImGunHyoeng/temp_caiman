// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/OBJECT_STATE/S_IDLE_O.h"
#include "OFSMCollection.h"
#include "CCharacterPlayer.h"
#include "CMyWeapon.h"
#include "AnimInstance\KwangAnimInstance.h"


TScriptInterface<IIPlayerState> US_IDLE_O::updateInput(ACCharacterPlayer& player)
{
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::SpaceBar))
	{
		return NewObject<UJUMP_O>();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::R))
	{
		player.Draw();
		return NewObject<UDRAWING_O>();
	}
	if (player.GetMoveInputActionValue().GetMagnitude() > 0.1f)
	{
		return NewObject<US_WALK_O>();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftControl))
	{
		player.StopMove();
		return NewObject<US_ROLL_O>();
	}
	return nullptr;
}

void US_IDLE_O::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
	return;
}

void US_IDLE_O::enter(ACCharacterPlayer& player)
{
	kwang = player.getAnimInstance();
	if (kwang)
		kwang->setSheath();
}

void US_IDLE_O::exit(ACCharacterPlayer& player)
{
}

void US_IDLE_O::Destroy()
{
	this->MarkPendingKill();
}
