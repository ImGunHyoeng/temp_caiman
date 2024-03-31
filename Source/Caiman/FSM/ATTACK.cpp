// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ATTACK.h"
#include "CCharacterPlayer.h"
#include "FSM_Collection.h"



IIPlayerState* ATTACK::updateInput(ACCharacterPlayer& player)
{
	if (player.GetWaitFrame() == 0)
	{
		//setPreviousState();
		//currentState = ECharacterState::D_IDLE;
		return new D_IDLE();
		//bWantCombo = false;
	}
	return NULL;
}

void ATTACK::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
	//if (PlayerController->WasInputKeyJustPressed(EKeys::LeftMouseButton))
	//	bWantCombo = true;
	//if (bIsCombo)
	//{
	//	ComboAttack();
	//	bIsCombo = false;
	//}
	player.WaitFramePassing();
	return;
}

void ATTACK::enter(ACCharacterPlayer& player)
{
	//ComboAttack();
}

void ATTACK::exit(ACCharacterPlayer& player)
{
}

void ATTACK::Destroy()
{
	delete this;
}
