// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FSM/IPlayerState.h"
#include "DRAWING_O.generated.h"

/**
 * 
 */
UCLASS()
class CAIMAN_API UDRAWING_O : public UObject,public IIPlayerState
{
	GENERATED_BODY()
	virtual TScriptInterface<IIPlayerState> updateInput(class ACCharacterPlayer& player);
	virtual void update(class ACCharacterPlayer& player);
	virtual void enter(class ACCharacterPlayer& player);
	virtual void exit(class ACCharacterPlayer& player);
	virtual void Destroy();
	//~S_WALK() { UE_LOG(LogTemp, Warning, TEXT("Walk Destroy")); }
};
