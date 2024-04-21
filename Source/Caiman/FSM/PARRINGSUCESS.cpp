// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/PARRINGSUCESS.h"
#include "AnimInstance\KwangAnimInstance.h"
#include "CCharacterPlayer.h"
#include "FSM_Collection.h"

PARRINGSUCESS::PARRINGSUCESS()
{
}

PARRINGSUCESS::~PARRINGSUCESS()
{
}

TScriptInterface<IIPlayerState> PARRINGSUCESS::updateInput(ACCharacterPlayer& player)
{
	//if (player.GetWaitFrame() < 0)
	//	//return new D_IDLE();
	return nullptr;
}

void PARRINGSUCESS::update(ACCharacterPlayer& player)
{
	player.WaitFramePassing();
	player.Look(player.GetLookInputActionValue());

}

void PARRINGSUCESS::enter(ACCharacterPlayer& player)
{
	kwang = player.getAnimInstance();
	player.StopAnimMontage(); 
	player.SetAttacked(true);
	player.PlayAnimMontage(player.GetParringMontage(), 1.0f, FName("Act"));
	player.SetWaitFrame(10);
	player.SetParring(false);
}

void PARRINGSUCESS::exit(ACCharacterPlayer& player)
{
	player.SetAttacked(false);
	
}

void PARRINGSUCESS::Destroy()
{
	delete this;
}
