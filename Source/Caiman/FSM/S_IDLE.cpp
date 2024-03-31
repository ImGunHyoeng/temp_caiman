// Fill out your copyright notice in the Description page of Project Settings.


#include "S_IDLE.h"
#include "FSM_Collection.h"
#include "CCharacterPlayer.h"
#include "CMyWeapon.h"
#include "AnimInstance\KwangAnimInstance.h"




IIPlayerState* S_IDLE::updateInput(ACCharacterPlayer& player)
{
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::SpaceBar))
	{
		//player.changeState(ECharacterState::JUMP);
		return new JUMP();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::R))
	{
		player.Draw();
		return new D_IDLE();
	}
	if (player.GetMoveInputActionValue().GetMagnitude() > 0.1f)
	{
		//player.changeState(ECharacterState::S_WALK);
		return new S_WALK();
	}
	return NULL;
}

void S_IDLE::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
	return;
}

void S_IDLE::enter(ACCharacterPlayer& player)
{
	kwang = player.getAnimInstance();
	if (kwang)
		kwang->setSheath();
}

void S_IDLE::exit(ACCharacterPlayer& player)
{

}

void S_IDLE::Destroy()
{
	delete this;
}
