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


// Called when the game starts
void UCTraceComponent::BeginPlay()
{
	Super::BeginPlay();
	
	if (WeaponMesh)
	{
		FVector Start = WeaponMesh->GetSocketLocation(FName("Start"));
		FVector End = WeaponMesh->GetSocketLocation(FName("End"));
	}
	// ...
	
}


// Called every frame
void UCTraceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (IsActive)
	{
		tracceobject
	}
	// ...
}

