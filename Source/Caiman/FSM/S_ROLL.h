// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM/IPlayerState.h"

/**
 *
 */
class CAIMAN_API S_ROLL :public IIPlayerState
{
public:
	S_ROLL();
	S_ROLL(FName _input) :input(_input) {}

	virtual IIPlayerState* updateInput(class ACCharacterPlayer& player);
	virtual void update(class ACCharacterPlayer& player);
	virtual void enter(class ACCharacterPlayer& player);
	virtual void exit(class ACCharacterPlayer& player);
	virtual void Destroy();

	class UKwangAnimInstance* kwang;
	FName input;
};