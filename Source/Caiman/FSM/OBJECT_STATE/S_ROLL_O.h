// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FSM/IPlayerState.h"
#include "S_ROLL_O.generated.h"

/**
 * 
 */
UCLASS()
class CAIMAN_API US_ROLL_O : public UObject,public IIPlayerState
{
	GENERATED_BODY()	
public:
	UPROPERTY(EditAnywhere, BluePrintReadOnly)
	bool isRoll;
	virtual TScriptInterface<IIPlayerState> updateInput(class ACCharacterPlayer& player);
	virtual void update(class ACCharacterPlayer& player);
	virtual void enter(class ACCharacterPlayer& player);
	virtual void exit(class ACCharacterPlayer& player);
	virtual void Destroy();
	virtual void updateInput() {}
	class UKwangAnimInstance* kwang;
	US_ROLL_O(){ isRoll = true; }
	
	FName input;
	//~S_WALK() { UE_LOG(LogTemp, Warning, TEXT("Walk Destroy")); }
};
