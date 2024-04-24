// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IPlayerState.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIPlayerState : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ACCharacterPlayer;
class PlayerStateFactory;
class CAIMAN_API IIPlayerState
{
	GENERATED_BODY()
public:
	virtual TScriptInterface<IIPlayerState> updateInput(class ACCharacterPlayer& player) = 0;	
	virtual void updateInput() = 0;
	virtual void update(class ACCharacterPlayer& player) = 0;
	virtual void update() = 0;
	virtual void enter( ACCharacterPlayer& player) = 0;
	virtual void InitializeSubState() = 0;
	virtual void exit( ACCharacterPlayer& player) = 0;
	virtual void Destroy() = 0;
	void UpdateStates()
	{
		update();
		if (currentSubstate != NULL)
		{
			currentSubstate->UpdateStates();
		}
	}
	IIPlayerState():IIPlayerState(NULL,NULL) {}
	IIPlayerState(ACCharacterPlayer *_ctx,PlayerStateFactory*_factory) 
	{
		ctx = _ctx;
		factory = _factory;
	}
	
	void SetInitalProperty(ACCharacterPlayer* _ctx, PlayerStateFactory* _factory)
	{
		ctx = _ctx;
		factory = _factory;
	}
	void SetRoot(bool _input=false) 
	{ isRootState = _input; }
protected:
	void SwitchState(TScriptInterface<IIPlayerState> newState);
	void SetSuperState(IIPlayerState* newSuperState)
	{
		currentSuperstate = newSuperState;
	}
	void SetSubState(IIPlayerState* newSubState)
	{
		currentSubstate = newSubState;
		newSubState->SetSuperState(this);
	}
	ACCharacterPlayer* ctx;
	PlayerStateFactory* factory;
	IIPlayerState* currentSuperstate;
	IIPlayerState* currentSubstate;
	bool isRootState;
};
