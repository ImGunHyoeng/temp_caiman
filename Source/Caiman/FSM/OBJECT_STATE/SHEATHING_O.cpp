// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/OBJECT_STATE/SHEATHING_O.h"
#include "OFSMCollection.h"
#include "CCharacterPlayer.h"
#include "Animation/AnimInstance.h"

TScriptInterface<IIPlayerState> USHEATHING_O::updateInput(ACCharacterPlayer& player)
{
	if (player.GetWaitFrame() <= 0)
	{
		return NewObject<US_IDLE_O>();
	}
	if (player.GetMoveInputActionValue().GetMagnitude() > 0.1f && player.GetWaitFrame() <= 6)
	{
		player.StopAnimMontage(player.GetSheathMontage());
		player.SetWaitFrame(0);
		return NewObject<US_IDLE_O>();
	}
	return nullptr;
}

void USHEATHING_O::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
	player.WaitFramePassing();
}

void USHEATHING_O::enter(ACCharacterPlayer& player)
{
	player.SetWaitFrame(8);
}

void USHEATHING_O::exit(ACCharacterPlayer& player)
{
}

void USHEATHING_O::Destroy()
{
	this->MarkPendingKill();

}
