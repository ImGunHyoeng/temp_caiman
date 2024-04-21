// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ATTACK.h"
#include "CCharacterPlayer.h"
#include "FSM_Collection.h"



TScriptInterface<IIPlayerState> ATTACK::updateInput(ACCharacterPlayer& player)
{
	/*if (curAttackState==EAttackState::END)
	{
		player.StopAnimMontage();
		return new D_IDLE();
	}*/

	return NULL;
}

void ATTACK::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());

	//if (curAttackState == EAttackState::DONE)
	//{
	//	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftMouseButton))
	//	{
	//		curAttackState = EAttackState::DOING;
	//		//DoingTime = 100;
	//		//player.SetWaitFrame(60);
	//		player.PlayAnimMontage(player.GetAttackMontage(), 1.0f, "Attack_2_2");
	//	}
	//}
}

void ATTACK::enter(ACCharacterPlayer& player)
{
	//DoingTime = 30;
	//curAttackState = EAttackState::DOING;
	player.PlayAnimMontage(player.GetAttackMontage(), 1.0f, "Attack_2_1");
}

void ATTACK::exit(ACCharacterPlayer& player)
{
}

void ATTACK::Destroy()
{
	delete this;
}
