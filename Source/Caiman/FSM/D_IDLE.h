// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM/IPlayerState.h"

/**
 *
 */
class CAIMAN_API D_IDLE :public IIPlayerState
{
public:
	virtual void updateInput(const class ACCharacterPlayer& player);
	virtual void update(const class ACCharacterPlayer& player);

};
