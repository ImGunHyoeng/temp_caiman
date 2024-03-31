// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/DRAWING.h"
#include "CCharacterPlayer.h"
#include "FSM_Collection.h"

DRAWING::DRAWING()
{
}

DRAWING::~DRAWING()
{
}

IIPlayerState* DRAWING::updateInput(ACCharacterPlayer& player)
{
	if (player.GetWaitFrame() <= 0)
	{
		return new D_IDLE();
	}
	if (player.GetMoveInputActionValue().GetMagnitude() > 0.1f && player.GetWaitFrame() <= 60)
	{
		
		player.StopAnimMontage(player.GetDrawMontage());
		player.SetWaitFrame(0);
		return new D_IDLE();
	}
	return NULL;
}

void DRAWING::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
	player.WaitFramePassing();
}

void DRAWING::enter(ACCharacterPlayer& player)
{
	player.SetWaitFrame(70);
}

void DRAWING::exit(ACCharacterPlayer& player)
{
}

void DRAWING::Destroy()
{
	delete this;
}
