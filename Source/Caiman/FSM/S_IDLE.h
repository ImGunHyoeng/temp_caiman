// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM/IPlayerState.h"

/**
 *
 */
class CAIMAN_API S_IDLE :public IIPlayerState
{
public:
	S_IDLE(){}
	virtual void updateInput(class ACCharacterPlayer& player);
	virtual void update(class ACCharacterPlayer& player);
};