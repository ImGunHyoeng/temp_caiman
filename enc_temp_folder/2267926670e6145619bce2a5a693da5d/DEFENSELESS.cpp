// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/DEFENSELESS.h"
#include "FSM_Collection.h"
#include "CCharacterPlayer.h"
#include "AnimInstance\KwangAnimInstance.h"


IIPlayerState* DEFENSELESS::updateInput(ACCharacterPlayer& player)
{
	if (player.GetWaitFrame() < 0)
	{
		return new D_IDLE();
	}
	return NULL;
}

void DEFENSELESS::update(ACCharacterPlayer& player)
{
	player.WaitFramePassing();
	player.Look(player.GetLookInputActionValue());
}

void DEFENSELESS::enter(ACCharacterPlayer& player)
{
	kwang = player.getAnimInstance();
	if (kwang)
		kwang->setDraw();
	player.SetWaitFrame(20);
}

void DEFENSELESS::exit(ACCharacterPlayer& player)
{

}

void DEFENSELESS::Destroy()
{
	delete this;
}
