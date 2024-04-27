// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FSM/IPlayerState.h"
#include "KNOCKBACK_A.generated.h"

UCLASS()
class CAIMAN_API AKNOCKBACK_A : public AActor,public IIPlayerState
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKNOCKBACK_A();
	virtual void updateInput();
	//virtual void update(class ACCharacterPlayer& player) = 0;
	virtual void update();
	virtual void enter();
	virtual void InitializeSubState();
	virtual void exit();
	virtual void Destroy();
	bool end;
	FVector ParticlePoint;
	void SetPoint(const FVector &ImpactPoint);
	void Start();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
