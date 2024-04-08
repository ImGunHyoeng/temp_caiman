// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/SHEATHING.h"
#include "CCharacterPlayer.h"
#include "FSM_Collection.h"
#include "Animation/AnimInstance.h"

SHEATHING::SHEATHING()
{
}

SHEATHING::~SHEATHING()
{
}

IIPlayerState* SHEATHING::updateInput(ACCharacterPlayer& player)
{
	if (player.GetWaitFrame() <= 0)
	{
		return new S_IDLE();
	}
	if (player.GetMoveInputActionValue().GetMagnitude() > 0.1f&& player.GetWaitFrame() <= 6)
	{
		player.StopAnimMontage(player.GetSheathMontage());
		player.SetWaitFrame(0);
		return new S_IDLE();
	}
    return NULL;
}

void SHEATHING::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
	player.WaitFramePassing();
}

void SHEATHING::enter(ACCharacterPlayer& player)
{
	player.SetWaitFrame(8);
}

void SHEATHING::exit(ACCharacterPlayer& player)
{

}

void SHEATHING::Destroy()
{
	delete this;
}
