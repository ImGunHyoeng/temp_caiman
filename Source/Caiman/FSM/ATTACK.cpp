// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ATTACK.h"
#include "CCharacterPlayer.h"
#include "FSM_Collection.h"



IIPlayerState* ATTACK::updateInput(ACCharacterPlayer& player)
{
	if (player.GetWaitFrame() <= 0)
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
	player.WaitFramePassing();
	DoingTime -= 1;
	//if (curAttackState == EAttackState::READY)
	if (DoingTime > 0)
		return;
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftMouseButton))
	{	
		DoingTime = 100;
		player.SetWaitFrame(60);
		player.PlayAnimMontage(player.GetAttackMontage(), 1.0f, "Attack_2_2");
	}
	
	
	
}

void ATTACK::enter(ACCharacterPlayer& player)
{
	DoingTime = 30;
	//curAttackState = EAttackState::DOING;
	//ComboAttack();
	//FString a = !bIsCombo ? TEXT("Attack_2_1") : TEXT("Attack_2_2");
	player.PlayAnimMontage(player.GetAttackMontage(), 1.0f, "Attack_2_1");
}

void ATTACK::exit(ACCharacterPlayer& player)
{
}

void ATTACK::Destroy()
{
	delete this;
}
