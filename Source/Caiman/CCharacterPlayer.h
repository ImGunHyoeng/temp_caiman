// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CCharacterBase.h"
#include "GameFramework/character.h"
#include "InputActionValue.h"
#include "CCharacterPlayer.generated.h"

UENUM(BlueprintType)
enum class ECharacterState :uint8
{
	S_IDLE,
	S_WALK,
	S_RUN,
	JUMP,
	LANDING,
	S_ROLL,
	D_IDLE,
	D_WALK,
	D_ROLL,
	JUMPATTACK,
	DEFENSELESS,
	PARRGING,
	ATTACK

	
	
};
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
	//매핑 텍스트

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
		TObjectPtr<class UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
		TObjectPtr<class UInputAction> MovementAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
		TObjectPtr<class UInputAction> DrawAction;
	
	UPROPERTY(EditAnywhere,BluePrintReadOnly, Category = Input)
	UInputAction* LookAction;
	
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = Input)
	UInputAction* RunAction;

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = Input)
	UInputAction* RollAction;

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = Input)
		TObjectPtr<class UInputAction> AttackAction;

	//몽타주

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = Montage)
		UAnimMontage* AM_Draw;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = Montage)
		UAnimMontage* AM_Sheath;

	//UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = Input)
	//UInputAction* JumpAction;*/
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Draw();
	void Roll(const FInputActionValue& Value);
	void Run(const FInputActionValue& Value);
	void Walk(const FInputActionValue& Value);
	void GoPrevious();
	void GoIdle(const FInputActionValue& Value);
	virtual void Jump() override;
	void Landing(); 
	void SetPrevious();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void DoAttack();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint32 bSwordDraw:1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint32 bIsJump:1;
	float moveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int WaitFrame;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint32 bIsAttack:1;



	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TObjectPtr<class ACMyWeapon> Weapon;

	TObjectPtr<class UEnhancedInputComponent> EnhancedInputComponent;
private:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
		ECharacterState currentState;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
		ECharacterState previousState;
	//virtual void SetCharacterControlData(const UABCharacterControlDataAsset* CharacterControlData);
};
