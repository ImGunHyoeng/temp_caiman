// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM/IPlayerState.h"

/**
 *
 */
class CAIMAN_API D_WALK :public IIPlayerState
{
public:
	virtual TScriptInterface<IIPlayerState> updateInput(class ACCharacterPlayer& player);
	virtual void update(class ACCharacterPlayer& player);
	virtual void enter(class ACCharacterPlayer& player);
	virtual void exit(class ACCharacterPlayer& player);
	virtual void Destroy();
};
