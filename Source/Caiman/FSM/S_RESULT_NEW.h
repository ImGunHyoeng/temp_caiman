// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM/S_IDLE_NEW.h"
#include "S_RESULT_NEW.generated.h"

/**
 * 
 */
UCLASS()
class CAIMAN_API US_RESULT_NEW : public US_IDLE_NEW
{
	GENERATED_BODY()
public:
	US_RESULT_NEW();
	virtual void updatechild(class ACCharacterPlayer& player) override;
	virtual TScriptInterface<IIPlayerState> updateInput(class ACCharacterPlayer& player);
	virtual void update(class ACCharacterPlayer& player);
	virtual void enter(class ACCharacterPlayer& player);
	virtual void exit(class ACCharacterPlayer& player);
	virtual void Destroy();
};
