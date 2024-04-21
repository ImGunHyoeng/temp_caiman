// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/OBJECT_STATE/DRAWING_O.h"
#include "CCharacterPlayer.h"
#include "OFSMCollection.h"

TScriptInterface<IIPlayerState> UDRAWING_O::updateInput(ACCharacterPlayer& player)
{
	if (player.GetWaitFrame() <= 0)
	{
		return NewObject<UD_IDLE_O>();
	}
	if (player.GetMoveInputActionValue().GetMagnitude() > 0.1f && player.GetWaitFrame() <= 6)
	{

		player.StopAnimMontage(player.GetDrawMontage());
		player.SetWaitFrame(0);
		return NewObject<UD_IDLE_O>();
	}
    return nullptr;
}

void UDRAWING_O::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
	player.WaitFramePassing();
}

void UDRAWING_O::enter(ACCharacterPlayer& player)
{
	player.SetWaitFrame(8);
}

void UDRAWING_O::exit(ACCharacterPlayer& player)
{
}

void UDRAWING_O::Destroy()
{
	this->MarkPendingKill();
}
