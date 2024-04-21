// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/OBJECT_STATE/JUMPATTACK_O.h"
#include "OFSMCollection.h"
#include "CCharacterPlayer.h"
#include "CMyWeapon.h"
#include "AnimInstance\KwangAnimInstance.h"
#include "Kismet/GameplayStatics.h"

TScriptInterface<IIPlayerState> UJUMPATTACK_O::updateInput(ACCharacterPlayer& player)
{
	if (player.GetWaitFrame() <= 0)
	{
		if (kwang)
			kwang->setJumpAttackEnd();
		return NewObject<UD_IDLE_O>();
	}
    return nullptr;
}

void UJUMPATTACK_O::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
	player.WaitFramePassing();
}

void UJUMPATTACK_O::enter(ACCharacterPlayer& player)
{
	kwang = player.getAnimInstance();
	if (kwang)
	{
		kwang->setDraw();
		kwang->setJumpAttack();
	}
}

void UJUMPATTACK_O::exit(ACCharacterPlayer& player)
{
}

void UJUMPATTACK_O::Destroy()
{
	this->MarkPendingKill();
}
