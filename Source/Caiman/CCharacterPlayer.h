// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CCharacterBase.h"
#include "GameFramework/character.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "FSM/IPlayerState.h"
#include "CCharacterPlayer.generated.h"

UENUM(BlueprintType)
enum class ECharacterState :uint8
{
	S_IDLE,
	S_WALK,
	S_RUN,
	JUMP,
	GROUNDED,
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
class CAIMAN_API ACCharacterPlayer : public ACCharacterBase,public IPlayerState
{
	GENERATED_BODY()
public:	
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = Camera)
	TObjectPtr<class USpringArmComponent>CameraBoom;//스프링암

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = Camera)
		TObjectPtr<class UCameraComponent>Camera;//카메라

	ACCharacterPlayer();
	void AttackCheck();
	void update();
	void updateInput();
	ECharacterState getCurState();
	void setCurState(ECharacterState state);
	APlayerController* getPlayerController();
	UInputAction* getInputAction(FString str);
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

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = Montage)
		UAnimMontage* AM_Attack;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = Montage)
		UAnimMontage* AM_Roll;

	//UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = Input)
	//UInputAction* JumpAction;*/
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


	void Move(const FInputActionValue& Value);
	//void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Draw();
	void NoAnimDraw();
	void Roll(const FInputActionValue& Value);
	void Run();
	void Walk();
	void GoPrevious();
	void GoWalk();
	void GoIdle();
	virtual void Jump() override;
	void Landing(); 
	void SetPrevious();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void JumpAttack();
	void Attack();
	void Roll();

	UFUNCTION(BlueprintImplementableEvent,category="Temp")
	void Attack_BP();

	
	void ComboAttack();

	UFUNCTION(BlueprintImplementableEvent, category = "Temp")
		void LateBeginPlay();
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint32 bSwordDraw:1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint32 bIsJump:1;
	float moveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int WaitFrame;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint32 bIsJumpAttack:1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint32 bIsCombo : 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint32 bWantCombo : 1;



	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TObjectPtr<class ACMyWeapon> Weapon;

	TObjectPtr<class UEnhancedInputComponent> EnhancedInputComponent;
	APlayerController* PlayerController;
	TArray<FEnhancedActionKeyMapping> KeyMappingArray;
	struct FEnhancedInputActionValueBinding* MoveActionBinding;
	struct FEnhancedInputActionValueBinding* LookActionBinding;
	struct FEnhancedInputActionValueBinding* JumpActionBinding;
	//struct FEnhancedInputActionValueBinding* RunActionBinding;
	//struct FEnhancedInputActionValueBinding* LookActionBinding;\

private:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
		ECharacterState currentState;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
		ECharacterState previousState;
	//virtual void SetCharacterControlData(const UABCharacterControlDataAsset* CharacterControlData);
};
