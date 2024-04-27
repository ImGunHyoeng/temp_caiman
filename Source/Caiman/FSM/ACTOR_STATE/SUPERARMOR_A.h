// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FSM/IPlayerState.h"
#include "SUPERARMOR_A.generated.h"


UCLASS()
class CAIMAN_API ASUPERARMOR_A : public AActor,public IIPlayerState
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASUPERARMOR_A();
	//virtual TScriptInterface<IIPlayerState> updateInput(class ACCharacterPlayer& player);
	virtual void updateInput();
	//virtual void update(class ACCharacterPlayer& player);
	virtual void update();
	virtual void enter();
	virtual void InitializeSubState();
	virtual void exit();
	virtual void Destroy();
	bool end;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
