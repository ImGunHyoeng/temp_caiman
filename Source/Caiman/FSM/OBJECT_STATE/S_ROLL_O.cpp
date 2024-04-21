// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/OBJECT_STATE/S_ROLL_O.h"
#include "AnimInstance\KwangAnimInstance.h"
#include "CCharacterPlayer.h"
#include "OFSMCollection.h"
TScriptInterface<IIPlayerState> US_ROLL_O::updateInput(ACCharacterPlayer& player)
{
	if (player.GetWaitFrame() < 0)
		return NewObject<US_IDLE_O>();
    return nullptr;
}

void US_ROLL_O::update(ACCharacterPlayer& player)
{
	player.WaitFramePassing();
	//player.Move(player.GetMoveInputActionValue());
	if (isRoll)
		player.AddMovementInput(player.GetActorForwardVector(), 2);
	player.Look(player.GetLookInputActionValue());
}

void US_ROLL_O::enter(ACCharacterPlayer& player)
{
	kwang = player.getAnimInstance();
	player.PlayAnimMontage(player.GetRollMontage(), 1.0f, input);
	player.SetWaitFrame(30);
}

void US_ROLL_O::exit(ACCharacterPlayer& player)
{
}

void US_ROLL_O::Destroy()
{
	this->MarkPendingKill();
}
