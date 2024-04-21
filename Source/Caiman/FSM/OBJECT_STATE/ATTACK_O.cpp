// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/OBJECT_STATE/ATTACK_O.h"
#include "CCharacterPlayer.h"
#include "OFSMCollection.h"

TScriptInterface<IIPlayerState> UATTACK_O::updateInput(ACCharacterPlayer& player)
{
	//if (curAttackState == EAttackState::END)
	//{
	//	player.StopAnimMontage();
	//	return NewObject<US_IDLE_O>();
	//}
	return nullptr;
}

void UATTACK_O::update(ACCharacterPlayer& player)
{
	//player.Look(player.GetLookInputActionValue());

	//if (curAttackState == EAttackState::DONE)
	//{
	//	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftMouseButton))
	//	{
	//		curAttackState = EAttackState::DOING;
	//		//DoingTime = 100;
	//		//player.SetWaitFrame(60);
	//		player.PlayAnimMontage(player.GetAttackMontage(), 1.0f, "Attack_2_2");
	//	}
	//}
}

void UATTACK_O::enter(ACCharacterPlayer& player)
{
	////DoingTime = 30;
	//curAttackState = EAttackState::DOING;
	//player.PlayAnimMontage(player.GetAttackMontage(), 1.0f, "Attack_2_1");
}

void UATTACK_O::exit(ACCharacterPlayer& player)
{
}

void UATTACK_O::Destroy()
{
	this->MarkPendingKill();
}
