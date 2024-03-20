// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM/IPlayerState.h"

/**
 *
 */
class CAIMAN_API PARRGING :public IIPlayerState
{
public:
	virtual void updateInput(class ACCharacterPlayer& player);
	virtual void update(class ACCharacterPlayer& player);
};