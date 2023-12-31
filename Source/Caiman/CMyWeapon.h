// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CTraceComponent.h"
#include "CMyWeapon.generated.h"

UCLASS()
class CAIMAN_API ACMyWeapon : public AActor
{
	GENERATED_BODY()
	
	float damage;
public:	
	// Sets default values for this actor's properties
	ACMyWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* Weapon;

	UFUNCTION(BlueprintPure)
	float getDamage() const { return damage; }

	UFUNCTION(BlueprintCallable)
	void setDamage(float input) { damage=input; }

	
};
