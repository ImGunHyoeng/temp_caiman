// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/OBJECT_STATE/JUMP_O.h"
#include "CCharacterPlayer.h"
#include "OFSMCollection.h"
#include "GameFramework\CharacterMovementComponent.h"
#include "AnimInstance/KwangAnimInstance.h"

TScriptInterface<IIPlayerState> UJUMP_O::updateInput(ACCharacterPlayer& player)
{
	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftMouseButton))
	{
		player.NoAnimDraw();
		player.SetWaitFrame(6);
		return NewObject<UJUMPATTACK_O>();
	}
	if (!(player.GetCharacterMovement()->IsFalling()))
	{
		return NewObject<UGROUNDED_O>();
	}
    return nullptr;
}

void UJUMP_O::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
}

void UJUMP_O::enter(ACCharacterPlayer& player)
{
	kwang = player.getAnimInstance();
	if (kwang)
		kwang->setJump();
	player.Super::Jump();
}

void UJUMP_O::exit(ACCharacterPlayer& player)
{
	if (kwang)
		kwang->setJumpEnd();
}

void UJUMP_O::Destroy()
{
	this->MarkPendingKill();
}
