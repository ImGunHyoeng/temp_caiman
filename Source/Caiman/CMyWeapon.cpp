// Fill out your copyright notice in the Description page of Project Settings.


#include "CMyWeapon.h"

// Sets default values
ACMyWeapon::ACMyWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//무기 오브젝트 만들고 애셋 적용하기
	Weapon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WEAPON"));
	Weapon->SetWorldScale3D(FVector(0.325f, 0.325f, 0.325f));
	UStaticMesh* SK_WEAPON=LoadObject<UStaticMesh>(nullptr,TEXT("/Script/Engine.StaticMesh'/Game/Mesh/Sketchfab_Sword_forsale.Sketchfab_Sword_forsale'"));
	if (SK_WEAPON)
	{
		Weapon->SetStaticMesh(SK_WEAPON);
		RootComponent = Weapon;
	}
	Weapon->SetCollisionProfileName(TEXT("NoCollision"));

}

// Called when the game starts or when spawned
void ACMyWeapon::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACMyWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

