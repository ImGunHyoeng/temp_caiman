// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/S_ROLL.h"
#include "AnimInstance\KwangAnimInstance.h"
#include "CCharacterPlayer.h"
#include "FSM_Collection.h"



IIPlayerState* S_ROLL::updateInput( ACCharacterPlayer& player)
{
	if(player.GetWaitFrame()<0)
		return new S_IDLE();
	return NULL;
}

void S_ROLL::update( ACCharacterPlayer& player)
{
	player.WaitFramePassing();
	player.Look(player.GetLookInputActionValue());
}

void S_ROLL::enter(ACCharacterPlayer& player)
{
	kwang = player.getAnimInstance();
	player.PlayAnimMontage(player.GetRollMontage(), 1.0f, input);
	player.SetWaitFrame(5);
}

void S_ROLL::exit(ACCharacterPlayer& player)
{
	
}

void S_ROLL::Destroy()
{
	delete this;
}
