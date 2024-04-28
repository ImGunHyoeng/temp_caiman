// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FSM/IPlayerState.h"
#include "D_IDLE_A.generated.h"

class ACCharacterPlayer;
class UPlayerStateFactory;
UCLASS()
class CAIMAN_API AD_IDLE_A : public AActor,public IIPlayerState
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AD_IDLE_A();
	AD_IDLE_A(ACCharacterPlayer* _ctx, UPlayerStateFactory* _factory) :IIPlayerState(_ctx, _factory) 
	{}
	//virtual IIPlayerState* updateInput(class ACCharacterPlayer& player);
	virtual void updateInput();
	virtual void update();
	//virtual void update(class ACCharacterPlayer& player);
	virtual void enter();
	virtual void exit();
	virtual void Destroy();
	virtual void InitializeSubState();
	class UKwangAnimInstance* kwang;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
