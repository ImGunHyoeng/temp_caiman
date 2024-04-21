// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/D_IDLE.h"
#include "FSM_Collection.h"
#include "CCharacterPlayer.h"
#include "AnimInstance\KwangAnimInstance.h"




TScriptInterface<IIPlayerState> D_IDLE::updateInput(ACCharacterPlayer& player)
{
	//if (!player.GetAttacked())
	//{
	//	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::R))
	//	{
	//		player.Sheath();
	//		//return new SHEATHING();
	//	}
	//	if (player.GetMoveInputActionValue().GetMagnitude() > 0.1f)
	//	{
	//		//return new D_WALK();
	//	}
	//	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftMouseButton))
	//	{
	//		player.SetWaitFrame(70);
	//		//return new ATTACK();
	//	}
	//	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::Q))
	//	{
	//		//return new PARRGING();
	//	}
	//}
	return NULL;
}

void D_IDLE::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
	
}

void D_IDLE::enter(ACCharacterPlayer& player)
{
	
	kwang = player.getAnimInstance();
	if (kwang)
		kwang->setDraw();
}

void D_IDLE::exit(ACCharacterPlayer& player)
{
}

void D_IDLE::Destroy()
{
	delete this;
}
