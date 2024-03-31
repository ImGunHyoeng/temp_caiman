// Fill out your copyright notice in the Description page of Project Settings.


#include "CMyWeapon.h"
#include "CTraceComponent.h"
// Sets default values
ACMyWeapon::ACMyWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//무기 오브젝트 만들고 애셋 적용하기
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WEAPON"));

	RootComponent = Weapon;
	//Weapon->SetWorldScale3D(FVector(0.325f, 0.325f, 0.325f));
	USkeletalMesh* SK_WEAPON=LoadObject<USkeletalMesh>(nullptr,TEXT("/Script/Engine.SkeletalMesh'/Game/Mesh/Sketchfab_Sword_forsale_Skeleton.Sketchfab_Sword_forsale_Skeleton'"));
	if (SK_WEAPON)
	{
		Weapon->SetSkeletalMesh(SK_WEAPON);
		
	}
	Weapon->SetCollisionProfileName(TEXT("NoCollision"));
	
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
	trace->WeaponMesh = Weapon;
	damage = 10.0f;
}

// Called every frame
void ACMyWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("Damage %f"),damage);
	
}



