// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/OBJECT_STATE/DEFENSELESS_O.h"
#include "OFSMCollection.h"
#include "CCharacterPlayer.h"
#include "AnimInstance\KwangAnimInstance.h"

TScriptInterface<IIPlayerState> UDEFENSELESS_O::updateInput(ACCharacterPlayer& player)
{
	if (player.GetWaitFrame() < 0)
	{
		return NewObject<UD_IDLE_O>();
	}
	return nullptr;
}

void UDEFENSELESS_O::update(ACCharacterPlayer& player)
{
	player.WaitFramePassing();
	player.Look(player.GetLookInputActionValue());
}

void UDEFENSELESS_O::enter(ACCharacterPlayer& player)
{
	player.SetParring(false);
	kwang = player.getAnimInstance();
	if (kwang)
		kwang->setDraw();
	player.SetWaitFrame(20);
}

void UDEFENSELESS_O::exit(ACCharacterPlayer& player)
{
}

void UDEFENSELESS_O::Destroy()
{
	this->MarkPendingKill();
}
