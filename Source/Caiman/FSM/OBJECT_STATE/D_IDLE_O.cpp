// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/OBJECT_STATE/D_IDLE_O.h"
#include "OFSMCollection.h"
#include "CCharacterPlayer.h"
#include "AnimInstance\KwangAnimInstance.h"

TScriptInterface<IIPlayerState> UD_IDLE_O::updateInput(ACCharacterPlayer& player)
{
	if (!player.GetAttacked())
	{
		if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::R))
		{
			player.Sheath();
			return NewObject<USHEATHING_O>();
		}
		if (player.GetMoveInputActionValue().GetMagnitude() > 0.1f)
		{
			return NewObject<UD_WALK_O>();
		}
		if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftMouseButton))
		{
			player.SetWaitFrame(70);
			return NewObject<UATTACK_O>();
		}
		if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::Q))
		{
			return NewObject<UPARRING_O>();
		}
	}
	return NULL;
}

void UD_IDLE_O::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
}

void UD_IDLE_O::enter(ACCharacterPlayer& player)
{
	kwang = player.getAnimInstance();
	if (kwang)
		kwang->setDraw();
}

void UD_IDLE_O::exit(ACCharacterPlayer& player)
{
}

void UD_IDLE_O::Destroy()
{
	this->MarkPendingKill();
}
