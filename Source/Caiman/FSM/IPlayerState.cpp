// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/IPlayerState.h"
#include "CCharacterPlayer.h"
// Add default functionality here for any IIPlayerState functions that are not pure virtual.

void IIPlayerState::SwitchState(TScriptInterface<IIPlayerState> newState)
{
	exit(*ctx);

	newState->enter(*ctx);
	ctx->setCurState(newState);
}
