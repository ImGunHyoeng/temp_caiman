// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FunctionalTest.h"
#include "FSMFunctionalTest.generated.h"

/**
 * 
 */
UCLASS()
class CAIMAN_API AFSMFunctionalTest : public AFunctionalTest
{
	GENERATED_BODY()
	AFSMFunctionalTest();

protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="FSM test data")
	TObjectPtr<class ACCharacterPlayer> Player;
	APlayerController* controller;
	virtual void BeginPlay()override;
	virtual void Tick(float DeltaTime) override;
	bool one = false;
	//UEnhancedInputLocalPlayerSubsystem* Subsystem;

	//UEnhancedPlayerInput* PlayerInput;

	//UInputAction* InputAction;

};
