// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "UObject/NoExportTypes.h"
#include "FSM/IPlayerState.h"
#include "S_IDLE_O.generated.h"

/**
 * 
 */
UCLASS()
class CAIMAN_API US_IDLE_O : public UObject, public IIPlayerState
{
	GENERATED_BODY()
	US_IDLE_O() {};
	virtual TScriptInterface<IIPlayerState> updateInput(class ACCharacterPlayer& player);
	virtual void update(class ACCharacterPlayer& player);
	virtual void enter(class ACCharacterPlayer& player);
	virtual void exit(class ACCharacterPlayer& player);
	~US_IDLE_O() { UE_LOG(LogTemp, Warning, TEXT("Idle Destroy")); }
	virtual void Destroy(); 
	virtual void updateInput() {}
	class UKwangAnimInstance* kwang;
};
