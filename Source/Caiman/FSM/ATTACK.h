// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM/IPlayerState.h"
UENUM()
enum class EAttackState :uint8
{
	READY
	,DOING
	,DONE
};
/**
*
 *
 */

class CAIMAN_API ATTACK :public IIPlayerState
{
public:
	virtual IIPlayerState* updateInput(class ACCharacterPlayer& player);
	virtual void update(class ACCharacterPlayer& player);
	virtual void enter(class ACCharacterPlayer& player);
	virtual void exit(class ACCharacterPlayer& player);
	virtual void Destroy();
	/*UFUNCTION(BlueprintCallable)
	void AttackStateReady() { curAttackState = EAttackState::READY; }
	UFUNCTION(BlueprintCallable)
	void AttackStateDone() { curAttackState = EAttackState::DONE; }*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAttackState curAttackState;

	int DoingTime;
};

