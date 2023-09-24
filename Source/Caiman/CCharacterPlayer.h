// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CCharacterBase.h"
#include "GameFramework/character.h"
#include "InputActionValue.h"
#include "CCharacterPlayer.generated.h"

/**
 * 
 */
UCLASS()
class CAIMAN_API ACCharacterPlayer : public ACCharacterBase
{
	GENERATED_BODY()
public:	
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = Camera)
	TObjectPtr<class USpringArmComponent>CameraBoom;//스프링암

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = Camera)
		TObjectPtr<class UCameraComponent>Camera;//카메라

	ACCharacterPlayer();
	
protected:

	UPROPERTY(EditAnywhere, Category = Input)
		class UInputMappingContext* PlayerContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
		TObjectPtr<class UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
		TObjectPtr<class UInputAction> MovementAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
		TObjectPtr<class UInputAction> DrawAction;
	
	UPROPERTY(EditAnywhere,BluePrintReadOnly, Category = Input)
	UInputAction* LookAction;

	//UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = Input)
	//UInputAction* JumpAction;*/
	virtual void BeginPlay() override;
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Draw(const FInputActionValue& Value);
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	bool bSwordDraw;
	//virtual void SetCharacterControlData(const UABCharacterControlDataAsset* CharacterControlData);
};
