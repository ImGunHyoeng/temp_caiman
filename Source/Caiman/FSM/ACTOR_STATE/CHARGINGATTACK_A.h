// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FSM/IPlayerState.h"
#include "CHARGINGATTACK_A.generated.h"
UENUM()
enum class EChargeAttackState :uint8
{
	STAY
	, START
	, DOING
	, DONE
};
UCLASS()
class CAIMAN_API ACHARGINGATTACK_A : public AActor, public IIPlayerState
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACHARGINGATTACK_A();
	virtual TScriptInterface<IIPlayerState> updateInput(class ACCharacterPlayer& player);
	virtual void updateInput();
	virtual void update();
	virtual void update(class ACCharacterPlayer& player);
	virtual void enter(class ACCharacterPlayer& player);
	virtual void exit(class ACCharacterPlayer& player);
	virtual void Destroy();
	virtual void InitializeSubState();
	UPROPERTY(BlueprintReadWrite)
	EChargeAttackState curstate;
	UAnimInstance* instance;
	float DoingTime;
	const float standardDoing = 2;
	UPROPERTY(BlueprintReadOnly)
	float resultWaitTime;

	const float ExtraTimeLimit=4;
	UPROPERTY(BlueprintReadWrite)
	bool changeState;
	UFUNCTION(BlueprintCallable)
	void ChangeDoing(class ACCharacterPlayer* player);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
