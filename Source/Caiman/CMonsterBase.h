// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CMonsterBase.generated.h"

UCLASS()
class CAIMAN_API ACMonsterBase : public ACharacter
{
	GENERATED_BODY()
	
		uint32 bIsLive : 1;
public:
	// Sets default values for this character's properties
	ACMonsterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float hp;
	//void ReceivePointDamage(float Damage,
	//	const class UDamageType* DamageType,
	//	FVector HitLocation,
	//	FVector HitNormal,
	//	class UPrimitiveComponent* HitComponent,
	//	FName BoneName,
	//	FVector ShotFromDirection,
	//	class AController* InstigatedBy,
	//	AActor* DamageCauser
	//) ;

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = Montage)
		UAnimMontage* AM_Hited;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = Montage)
		UAnimMontage* AM_Dead;
	virtual float InternalTakePointDamage(float Damage, struct FPointDamageEvent const& PointDamageEvent, class AController* EventInstigator, AActor* DamageCauser)override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
};
