// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/GROUNDED.h"
#include "FSM_Collection.h"
#include "CCharacterPlayer.h"
#include "AnimInstance\KwangAnimInstance.h"

IIPlayerState* GROUNDED::updateInput(ACCharacterPlayer& player)
{
	
	if (player.GetWaitFrame()== 0)
	{
		return new S_IDLE();
	}
	
	return NULL;
}

void GROUNDED::update(ACCharacterPlayer& player)
{
	player.WaitFramePassing();
}

void GROUNDED::enter(ACCharacterPlayer& player)
{
	kwang = player.getAnimInstance();
	player.SetWaitFrame(5);
}

void GROUNDED::exit(ACCharacterPlayer& player)
{
	
}

void GROUNDED::Destroy()
{
	delete this;
}
