// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CAIMAN_API ACPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	void BeginPlay() override;
};
