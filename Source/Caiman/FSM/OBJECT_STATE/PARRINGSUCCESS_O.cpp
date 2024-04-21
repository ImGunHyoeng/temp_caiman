// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/OBJECT_STATE/PARRINGSUCCESS_O.h"
#include "AnimInstance\KwangAnimInstance.h"
#include "CCharacterPlayer.h"
#include "OFSMCollection.h"

TScriptInterface<IIPlayerState> UPARRINGSUCCESS_O::updateInput(ACCharacterPlayer& player)
{
	if (player.GetWaitFrame() < 0)
		return NewObject<UD_IDLE_O>();
    return nullptr;
}

void UPARRINGSUCCESS_O::update(ACCharacterPlayer& player)
{
	player.WaitFramePassing();
	player.Look(player.GetLookInputActionValue());
}

void UPARRINGSUCCESS_O::enter(ACCharacterPlayer& player)
{
	kwang = player.getAnimInstance();
	player.StopAnimMontage();
	player.SetAttacked(true);
	player.PlayAnimMontage(player.GetParringMontage(), 1.0f, FName("Act"));
	player.SetWaitFrame(10);
	player.SetParring(false);
}

void UPARRINGSUCCESS_O::exit(ACCharacterPlayer& player)
{
	player.SetAttacked(false);
}

void UPARRINGSUCCESS_O::Destroy()
{
	this->MarkPendingKill();
}
