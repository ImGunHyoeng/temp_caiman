// Fill out your copyright notice in the Description page of Project Settings.


#include "CTraceComponent.h"

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
	if (!IsActive)
		return;
	start = WeaponMesh->GetSocketLocation(FName("Start"));
	end = WeaponMesh->GetSocketLocation(FName("End"));
	dir = end - start;
	//Dir.Size();
	
	UE_LOG(LogTemp, Warning,TEXT("End:%s"), *end.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Start:%s"), *start.ToString());
	//if (IsActive)
	
	mySphere = FCollisionShape::MakeSphere(10);
	GetWorld()->SweepMultiByChannel(outResults, start, end, FQuat::Identity, ECollisionChannel::ECC_GameTraceChannel1, mySphere);
	//DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 5.0f);
	color = outResults.IsEmpty() ? FColor::Red : FColor::Green;
	//if(!outResults.IsEmpty())
	DrawDebugCapsule(GetWorld(),(start+end)/2, dir.Size()*0.5+10,10, FRotationMatrix::MakeFromZ(dir).ToQuat(),color, false, 2.0f);
		////DrawDebugSphere()
	/*else
	{
			DrawDebugCapsule(GetWorld(), (Start + End) / 2, Dir.Size() * 0.5 + 10, 10, FRotationMatrix::MakeFromZ(Dir).ToQuat(), FColor::Red, false, 2.0f);
	}*/
	
	// ...
}

