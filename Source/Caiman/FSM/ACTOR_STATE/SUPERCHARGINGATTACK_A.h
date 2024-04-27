// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM/ACTOR_STATE/CHARGINGATTACK_A.h"
#include "SUPERCHARGINGATTACK_A.generated.h"

/**
 * 
 */
UCLASS()
class CAIMAN_API ASUPERCHARGINGATTACK_A : public ACHARGINGATTACK_A
{
	GENERATED_BODY()
	virtual void updateInput();
	virtual void update();
	virtual void enter();
	virtual void exit();
	virtual void Destroy();
	virtual void InitializeSubState();
};
