// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FSM/IPlayerState.h"
#include "S_ROLL_A.generated.h"
class ACCharacterPlayer;
class PlayerStateFactory;
UCLASS()
class CAIMAN_API AS_ROLL_A : public AActor,public IIPlayerState
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AS_ROLL_A();
	AS_ROLL_A
	(ACCharacterPlayer* _ctx, PlayerStateFactory* _factory) :IIPlayerState(_ctx, _factory)
	{}
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isRoll;
	virtual TScriptInterface<IIPlayerState> updateInput(class ACCharacterPlayer& player);
	virtual void updateInput();
	virtual void update(class ACCharacterPlayer& player);
	virtual void enter(class ACCharacterPlayer& player);
	virtual void exit(class ACCharacterPlayer& player);
	virtual void Destroy();
	class UKwangAnimInstance* kwang;
	

	FName input;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
