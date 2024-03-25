// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/S_WALK.h"
#include "CCharacterPlayer.h"
#include "FSM\S_RUN.h"
#include "FSM/D_IDLE.h"
#include "CMyWeapon.h"
#include "GameFramework/CharacterMovementComponent.h"


IIPlayerState * S_WALK::updateInput(ACCharacterPlayer& player)
{
	if (player.getPlayerController()->IsInputKeyDown(EKeys::LeftShift))
	{
		//changeState(ECharacterState::S_RUN);
		return new S_RUN();
	}
	if (player.GetMoveInputActionValue().GetMagnitude() < 0.1f)
	{
		//changeState(ECharacterState::S_IDLE);
		return new S_IDLE();
	}
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::R))
	{
		player.GetWeapon()->AttachToComponent(player.GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("S_Draw"));
		player.PlayAnimMontage(player.GetDrawMontage());
		//player.changeState(ECharacterState::D_IDLE);
		//NoAnimDraw();
		//PlayAnimMontage(AM_Draw);
		//changeState(ECharacterState::D_IDLE);
		return new D_IDLE();
	}
	return NULL;
}

void S_WALK::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
	
	//set this enter
	player.Move(player.GetMoveInputActionValue());
}

void S_WALK::enter(ACCharacterPlayer& player)
{
	player.GetCharacterMovement()->MaxWalkSpeed = 1000 / 2.0f;
}

void S_WALK::exit(ACCharacterPlayer& player)
{
}

void S_WALK::Destroy()
{
	delete this;
}
