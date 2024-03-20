// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/S_IDLE.h"
#include "CCharacterPlayer.h"
#include "CMyWeapon.h"



void S_IDLE::updateInput(ACCharacterPlayer& player)
{
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::SpaceBar))
	{
		player.changeState(ECharacterState::JUMP);
		return;
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::R))
	{
		player.GetWeapon()->AttachToComponent(player.GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("S_Draw"));
		player.PlayAnimMontage(player.GetDrawMontage());
		player.changeState(ECharacterState::D_IDLE);
		return;
	}
	if (player.GetMoveInputActionValue().GetMagnitude() > 0.1f)
	{
		player.changeState(ECharacterState::S_WALK);
		return;
	}
}

void S_IDLE::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
	return;
}
