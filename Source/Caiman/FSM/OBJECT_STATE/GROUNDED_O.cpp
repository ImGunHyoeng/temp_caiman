// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/OBJECT_STATE/GROUNDED_O.h"
#include "OFSMCollection.h"
#include "CCharacterPlayer.h"
#include "AnimInstance\KwangAnimInstance.h"

TScriptInterface<IIPlayerState> UGROUNDED_O::updateInput(ACCharacterPlayer& player)
{
	if (player.GetWaitFrame() <= 0)
	{
		return NewObject<US_IDLE_O>();
	}
	return nullptr;
}

void UGROUNDED_O::update(ACCharacterPlayer& player)
{
	player.WaitFramePassing();
}

void UGROUNDED_O::enter(ACCharacterPlayer& player)
{
	kwang = player.getAnimInstance();
	player.SetWaitFrame(3);
}

void UGROUNDED_O::exit(ACCharacterPlayer& player)
{
}

void UGROUNDED_O::Destroy()
{
	this->MarkPendingKill();
}
