// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/OBJECT_STATE/PARRING_O.h"
#include "AnimInstance\KwangAnimInstance.h"
#include "CCharacterPlayer.h"
#include "OFSMCollection.h"

TScriptInterface<IIPlayerState> UPARRING_O::updateInput(ACCharacterPlayer& player)
{
	if (player.GetParringEnd() == true)
	{
		return NewObject<UDEFENSELESS_O>();
	}
	return nullptr;
}

void UPARRING_O::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
}

void UPARRING_O::enter(ACCharacterPlayer& player)
{
	kwang = player.getAnimInstance();
	player.PlayAnimMontage(player.GetParringMontage(), 1.0f);
	//player.SetWaitFrame(30);
	player.SetParring(true);
	player.SetParringEnd(false);
}

void UPARRING_O::exit(ACCharacterPlayer& player)
{
	player.SetWaitFrame(0);
}

void UPARRING_O::Destroy()
{
	this->MarkPendingKill();
}
