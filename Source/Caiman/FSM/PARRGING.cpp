// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/PARRGING.h"
#include "AnimInstance\KwangAnimInstance.h"
#include "CCharacterPlayer.h"
#include "FSM_Collection.h"


TScriptInterface<IIPlayerState> PARRGING::updateInput(ACCharacterPlayer& player)
{
	//if (player.GetParringEnd() == true)
	//{
	//	//return new DEFENSELESS();
	//}
	return NULL;
}

void PARRGING::update(ACCharacterPlayer& player)
{
	//player.WaitFramePassing();
	player.Look(player.GetLookInputActionValue());
}

void PARRGING::enter(ACCharacterPlayer& player)
{
	kwang = player.getAnimInstance();
	player.PlayAnimMontage(player.GetParringMontage(), 1.0f);
	//player.SetWaitFrame(30);
	player.SetParring(true);
	player.SetParringEnd(false);
}

void PARRGING::exit(ACCharacterPlayer& player)
{
	player.SetWaitFrame(0);
	
}

void PARRGING::Destroy()
{
	delete this;
}
