// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/D_WALK.h"
#include "FSM_Collection.h"
#include "CCharacterPlayer.h"
#include "CMyWeapon.h"



IIPlayerState* D_WALK::updateInput(ACCharacterPlayer& player)
{
	if (player.GetMoveInputActionValue().GetMagnitude() < 0.1f)
	{
		//changeState(ECharacterState::D_IDLE);
		return new D_IDLE();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftMouseButton))
	{
		//setPreviousState();
		//currentState = ECharacterState::ATTACK;
		//WaitFrame = 70;
		player.SetWaitFrame(70);
		//ComboAttack();
		return new ATTACK();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::R))
	{
		//changeState(ECharacterState::S_IDLE);
		player.Sheath();
		return new SHEATHING();
	}
	return NULL;
}

void D_WALK::update(ACCharacterPlayer& player)
{
	player.Move(player.GetMoveInputActionValue());
	player.Look(player.GetLookInputActionValue());
}

void D_WALK::enter(ACCharacterPlayer& player)
{
}

void D_WALK::exit(ACCharacterPlayer& player)
{
}

void D_WALK::Destroy()
{
	delete this;
}
