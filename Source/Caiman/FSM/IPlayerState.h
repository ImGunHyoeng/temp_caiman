// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class CAIMAN_API IPlayerState
{
public:
	IPlayerState();
	virtual void updateInput()=0;
	virtual void update()=0;
	virtual ~ IPlayerState();
};
