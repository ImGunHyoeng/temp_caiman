// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/JUMP.h"
#include "CCharacterPlayer.h"
#include "FSM_Collection.h"
#include "GameFramework\CharacterMovementComponent.h"
#include "AnimInstance/KwangAnimInstance.h"

TScriptInterface<IIPlayerState> JUMP::updateInput(ACCharacterPlayer& player)
{

	//if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftMouseButton))
	//{
	//	player.NoAnimDraw();
	//	player.SetWaitFrame(6);
	////	return new JUMPATTACK();
	//}
	//if (!(player.GetCharacterMovement()->IsFalling()))
	//{
	////	return new GROUNDED();
	//}

	return NULL;
}


void JUMP::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
}

void JUMP::enter(ACCharacterPlayer& player)
{
	kwang = player.getAnimInstance();
	if (kwang)
		kwang->setJump();
	player.Super::Jump();
}

void JUMP::exit(ACCharacterPlayer& player)
{
	if (kwang)
		kwang->setJumpEnd();
}

void JUMP::Destroy()
{
	delete this;
}
