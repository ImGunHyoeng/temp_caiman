// Fill out your copyright notice in the Description page of Project Settings.


#include "CMyWeapon.h"
#include "CTraceComponent.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
ACMyWeapon::ACMyWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//무기 오브젝트 만들고 애셋 적용하기
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));

	RootComponent = WeaponMesh;
	WeaponMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	
	trace = CreateDefaultSubobject<UCTraceComponent>(FName("TRACE"));
	//trace = CreateDefaultSubobject<UCTraceComponent>(TEXT("Mytrace"));
}

UCTraceComponent* ACMyWeapon::getTrace()
{
	return trace;
}

// Called when the game starts or when spawned
void ACMyWeapon::BeginPlay()
{
	Super::BeginPlay();
	trace->WeaponMesh = WeaponMesh;
	damage = 10.0f;
}

// Called every frame
void ACMyWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("Damage %f"),damage);
	
}



