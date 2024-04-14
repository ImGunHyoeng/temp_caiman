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
		return new JUMP();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::R))
	{
		player.Draw();
		return new DRAWING();
	}
	if (player.GetMoveInputActionValue().GetMagnitude() > 0.1f)
	{
		return new S_WALK();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftControl))
	{
		return new S_ROLL(FName("Front"));
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
