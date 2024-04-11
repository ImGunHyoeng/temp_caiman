// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Hit\HitInterface.h"
#include "EnemyBase.generated.h"

UENUM()
enum class EEnemyState :uint8
{
	STROLL,
	ATTACK,
	FLEE,
	MOVETOWARDPLAYER
};

UCLASS()
class CAIMAN_API AEnemyBase : public APawn, public IHitInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemyBase();

protected:
	// Called when the game starts or when spawned
	EEnemyState Curstate;
	virtual void BeginPlay() override;
	
	//UFUNCTION()
	//virtual void OutAttackRange(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	virtual void PlayerInRange(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	//FComponentBeginOverlapSignature, UPrimitiveComponent, OnComponentBeginOverlap, UPrimitiveComponent*, OverlappedComponent, AActor*, OtherActor, UPrimitiveComponent*, OtherComp, int32, OtherBodyIndex, bool, bFromSweep, const FHitResult&, SweepResult
	UFUNCTION()
	virtual void InAttackRange(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	//FComponentEndOverlapSignature, UPrimitiveComponent, OnComponentEndOverlap, UPrimitiveComponent*, OverlappedComponent, AActor*, OtherActor, UPrimitiveComponent*, OtherComp, int32, OtherBodyIndex
	//UFUNCTION()
	//virtual void PlayerOutRange(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	class UEnemyInstance* enemyaniminstance;

	virtual void Update();
	virtual void UpdateInput();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	class USkeletalMeshComponent* Bone;

	UPROPERTY(VisibleAnyWhere, Category = "Collision")
	class UCapsuleComponent* Body;

	UPROPERTY(VisibleAnyWhere,Category= "Collision")
	class USphereComponent* DetectStartRange;

	UPROPERTY(VisibleAnyWhere, Category = "Collision")
	class USphereComponent* DetectEndRange;
	
	UPROPERTY(VisibleAnyWhere, Category = "Collision")
	class USphereComponent* AttackStatrRange;
	
	UPROPERTY(VisibleAnyWhere, Category = "Collision")
	class USphereComponent* AttackEndRange;

	class ACCharacterPlayer* player;
	UPROPERTY(EditAnywhere, Category = VisualEffect)
	UParticleSystem* HittedParticle;
	int hp;
	virtual void GetHit_Implementation(const FVector& ImpactPoint) override;
	
	FVector  spawnpoint;
	FVector  targetLocation;
	FVector  direction;
	bool targetSet;
};
