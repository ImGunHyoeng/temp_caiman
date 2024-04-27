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
	//virtual TScriptInterface<IIPlayerState> updateInput(class ACCharacterPlayer& player) = 0;	
	virtual void updateInput() {};
	//virtual void update(class ACCharacterPlayer& player) = 0;
	virtual void update() {};
	virtual void enter() {};
	virtual void InitializeSubState() {};
	virtual void exit() {};
	virtual void Destroy() {};
	void UpdateStates();
	void EnterStates();
	void ExitStates();

	IIPlayerState():IIPlayerState(NULL,NULL) {}
	IIPlayerState(ACCharacterPlayer *_ctx,PlayerStateFactory*_factory) 
	{
		ctx = _ctx;
		factory = _factory;
	}
	
	void SetInitalProperty(ACCharacterPlayer* _ctx, PlayerStateFactory* _factory);

	void SetRoot(bool _input = false);

	void SwitchState(TScriptInterface<IIPlayerState> newState);
	TScriptInterface<IIPlayerState> GetSubState();
protected:
	void SetSuperState(TScriptInterface<IIPlayerState> newSuperState);

	void SetSubState(TScriptInterface<IIPlayerState> newSubState);

	//UPROPERTY()
	ACCharacterPlayer* ctx;
	//UPROPERTY()
	PlayerStateFactory* factory;
	TScriptInterface<IIPlayerState> currentSuperstate;
	TScriptInterface<IIPlayerState> currentSubstate;
	bool isRootState;
};
