// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FSM/IPlayerState.h"
#include "S_IDLE_NEWA.generated.h"

UCLASS()
class CAIMAN_API AS_IDLE_NEWA :public AActor ,public IIPlayerState
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AS_IDLE_NEWA();
	virtual TScriptInterface<IIPlayerState> updateInput(class ACCharacterPlayer& player) ;
	virtual void update(class ACCharacterPlayer& player) ;
	virtual void enter(class ACCharacterPlayer& player) ;
	virtual void exit(class ACCharacterPlayer& player) ;
	virtual void Destroy() ;
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	

};
