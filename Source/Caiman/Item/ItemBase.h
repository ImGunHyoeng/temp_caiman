// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DataBase/ItemData.h"
#include "ItemBase.generated.h"

UCLASS()
class CAIMAN_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBase();

	UPROPERTY(VisibleAnywhere, Category = Mesh)
	USkeletalMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, Category = Values)
	float Power;
	UFUNCTION(BlueprintPure)
	float getPower() const { return Power; }

	UFUNCTION(BlueprintCallable)
	void setPower(float input) { Power = input; }
	UPROPERTY(EditAnywhere, Category = Data)
	FItemSlot Item;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
