// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CMyWeapon.generated.h"

class UCTraceComponent;
UCLASS()
class CAIMAN_API ACMyWeapon : public AActor
{
	GENERATED_BODY()
	
	float damage;
public:	
	// Sets default values for this actor's properties
	ACMyWeapon();
	UCTraceComponent* getTrace();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	USkeletalMeshComponent* WeaponMesh;

	UFUNCTION(BlueprintPure)
	float getDamage() const { return damage; }

	UFUNCTION(BlueprintCallable)
	void setDamage(float input) { damage=input; }
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCTraceComponent* trace;

	UFUNCTION(BlueprintCallable)
	UParticleSystem* GetHitParticle() { return HitParticle; }
	UFUNCTION(BlueprintCallable)
	UParticleSystem* GetJumpAttackParticle() { return JumpAttackParticle; }
	UPROPERTY(EditAnywhere, Category = VisualEffect)
	UParticleSystem* HitParticle;
	UPROPERTY(EditAnywhere, Category = VisualEffect)
	UParticleSystem* JumpAttackParticle;

};
