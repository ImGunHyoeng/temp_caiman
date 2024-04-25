// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/IPlayerState.h"
#include "CCharacterPlayer.h"
// Add default functionality here for any IIPlayerState functions that are not pure virtual.

void IIPlayerState::SetInitalProperty(ACCharacterPlayer* _ctx, PlayerStateFactory* _factory)
{
	
	ctx = _ctx;
	factory = _factory;
	
}

void IIPlayerState::SetRoot(bool _input)
{
	 isRootState = _input;
}

void IIPlayerState::SwitchState(TScriptInterface<IIPlayerState> newState)
{
	ExitStates();
	newState->EnterStates();
	if(isRootState)
		ctx->setCurState(newState);
	else if (currentSuperstate != NULL)
	{
		currentSuperstate->SetSubState(newState);
	}
}

TScriptInterface<IIPlayerState> IIPlayerState::GetSubState()
{
	return currentSubstate;
}

void IIPlayerState::SetSuperState(TScriptInterface<IIPlayerState> newSuperState)
{
	currentSuperstate = newSuperState;
}

void IIPlayerState::SetSubState(TScriptInterface<IIPlayerState> newSubState)
{
	currentSubstate = newSubState;
	newSubState->SetSuperState(this->_getUObject());
}



void IIPlayerState::UpdateStates()
{
	update();
	if (currentSubstate == NULL)
		return;
	currentSubstate->UpdateStates();
	
}

void IIPlayerState::EnterStates()
{
	enter();
	if (currentSubstate == NULL)
		return;
	currentSubstate->EnterStates();
}

void IIPlayerState::ExitStates()
{
	exit();
	if (currentSubstate == NULL)
		return;
	currentSubstate->ExitStates();
}
