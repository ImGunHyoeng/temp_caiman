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
class CAIMAN_API IIPlayerState
{
	GENERATED_BODY()
public:
	virtual TScriptInterface<IIPlayerState> updateInput(class ACCharacterPlayer& player) = 0;
	virtual void update(class ACCharacterPlayer& player) = 0;
	virtual void enter(class ACCharacterPlayer& player) = 0;
	virtual void exit(class ACCharacterPlayer& player) = 0;
	virtual void Destroy() = 0;
};
