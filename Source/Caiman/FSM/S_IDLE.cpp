// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/S_IDLE.h"
#include "FSM\D_IDLE.h"
#include "FSM\JUMP.h"
#include "FSM\S_WALK.h"
#include "CCharacterPlayer.h"
#include "CMyWeapon.h"




IIPlayerState* S_IDLE::updateInput(ACCharacterPlayer& player)
{
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::SpaceBar))
	{
		//player.changeState(ECharacterState::JUMP);
		return new JUMP();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::R))
	{
		player.GetWeapon()->AttachToComponent(player.GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("S_Draw"));
		player.PlayAnimMontage(player.GetDrawMontage());
		//player.changeState(ECharacterState::D_IDLE);
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
}

void S_IDLE::exit(ACCharacterPlayer& player)
{
}

void S_IDLE::Destroy()
{
	delete this;
}
