// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FSM/IPlayerState.h"
#include "ATTACK_A.generated.h"

UENUM()
enum class EAttackState :uint8
{
	END
	, DONE
	, DOING
};

UCLASS()
class CAIMAN_API AATTACK_A : public AActor,public IIPlayerState
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AATTACK_A();
	virtual TScriptInterface<IIPlayerState> updateInput(class ACCharacterPlayer& player);
	virtual void update(class ACCharacterPlayer& player);
	virtual void enter(class ACCharacterPlayer& player);
	virtual void exit(class ACCharacterPlayer& player);
	virtual void Destroy();

	UFUNCTION(BlueprintCallable)
	void AttackStateEnd() { curAttackState = EAttackState::END; }
	UFUNCTION(BlueprintCallable)
	void AttackStateDone() { curAttackState = EAttackState::DONE; }
	UFUNCTION(BlueprintCallable)
	void AttackStateDoing() { curAttackState = EAttackState::DOING; }
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAttackState curAttackState;


	int DoingTime;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
