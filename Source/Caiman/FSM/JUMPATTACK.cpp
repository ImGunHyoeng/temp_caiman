// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/JUMPATTACK.h"
#include "FSM_Collection.h"
#include "CCharacterPlayer.h"
#include "CMyWeapon.h"
#include "AnimInstance\KwangAnimInstance.h"
#include "Kismet/GameplayStatics.h"


IIPlayerState* JUMPATTACK::updateInput(ACCharacterPlayer& player)
{
	
	
	if (player.GetWaitFrame() == 0)
	{
		if(kwang)
			kwang->setJumpAttackEnd();
		return new D_IDLE();
	}
	
	return NULL;
}

void JUMPATTACK::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
	player.WaitFramePassing();
	return;
}

void JUMPATTACK::enter(ACCharacterPlayer& player)
{
	kwang = player.getAnimInstance();
	if (kwang)
	{
		kwang->setDraw();
		kwang->setJumpAttack();
	}
	player.SetAttackParticle(player.GetJumpAttackParticle());
}

void JUMPATTACK::exit(ACCharacterPlayer& player)
{
	player.SetAttackParticle(player.GetNormalAttackParticle());
}

void JUMPATTACK::Destroy()
{
	delete this;
}
