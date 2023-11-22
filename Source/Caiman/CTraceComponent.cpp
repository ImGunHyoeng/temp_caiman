// Fill out your copyright notice in the Description page of Project Settings.


#include "CTraceComponent.h"
#include "CMyWeapon.h"

// Sets default values for this component's properties
UCTraceComponent::UCTraceComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}







void UCTraceComponent::InitializeComponent()
{
	Super::InitializeComponent();
	
}

void UCTraceComponent::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UCTraceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!WeaponMesh)
		return;
	
	Start = WeaponMesh->GetSocketLocation(FName("Start"));
	End = WeaponMesh->GetSocketLocation(FName("End"));
	FVector Dir = End - Start;
	//Dir.Size();
	
	//UE_LOG(Logtmep,LogTemp,"%s", ECollisionChannel::ECC_GameTraceChannel1)
	//if (IsActive)
	
	FCollisionShape MySphere = FCollisionShape::MakeSphere(10);
	TArray<FHitResult> OutResults;
	GetWorld()->SweepMultiByChannel(OutResults, Start, End, FQuat::Identity, ECollisionChannel::ECC_GameTraceChannel1, MySphere);
	//DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 5.0f);
	if(!OutResults.IsEmpty())
	DrawDebugCapsule(GetWorld(),(Start+End)/2, Dir.Size()*0.5+10,10, FRotationMatrix::MakeFromZ(Dir).ToQuat(),FColor::Green, false, 0.1f);
		////DrawDebugSphere()
	else
	{
			DrawDebugCapsule(GetWorld(), (Start + End) / 2, Dir.Size() * 0.5 + 10, 10, FRotationMatrix::MakeFromZ(Dir).ToQuat(), FColor::Red, false, 0.1f);
	}
	
	// ...
}

