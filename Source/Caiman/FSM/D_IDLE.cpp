// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/D_IDLE.h"
#include "FSM_Collection.h"
#include "CCharacterPlayer.h"
#include "AnimInstance\KwangAnimInstance.h"



IIPlayerState* D_IDLE::updateInput(ACCharacterPlayer& player)
{
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::R))
	{
		//changeState(ECharacterState::S_IDLE);
		player.Sheath();
		return new S_IDLE();
	}
	if (player.GetMoveInputActionValue().GetMagnitude() > 0.1f)
	{
		//changeState(ECharacterState::D_WALK);
		return new D_WALK();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftMouseButton))
	{
		//setPreviousState();
		//currentState = ECharacterState::ATTACK;
		player.SetWaitFrame(70);// WaitFrame = 70;
		//ComboAttack();
		return new ATTACK();
	}
	return NULL;
}

void D_IDLE::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
	
}

void D_IDLE::enter(ACCharacterPlayer& player)
{
	kwang = player.getAnimInstance();
	if (kwang)
		kwang->setDraw();
}

void D_IDLE::exit(ACCharacterPlayer& player)
{
}

void D_IDLE::Destroy()
{
	delete this;
}
