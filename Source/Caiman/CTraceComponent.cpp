// Fill out your copyright notice in the Description page of Project Settings.


#include "CTraceComponent.h"
#include "CMonsterBase.h"
#include "Kismet/GameplayStatics.h"
#include "CMyWeapon.h"
#include "EngineUtils.h"
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
	{
		if(attackObj.Num()==0)
			return;
		attackObj.Reset();
		return;
	}
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

	for (const auto & result : outResults)
	{
		
		//AActor* tempa;
		//tempa = WeaponMesh->GetOwner();
		////result.GetActor();
		
		ACMyWeapon* temp= Cast<ACMyWeapon>(WeaponMesh->GetOwner());
		ACMonsterBase* monster= Cast<ACMonsterBase>(result.GetActor());
		if (!IsValid(monster) || temp->getDamage() == 0)
			return;
		if (monster->getHp() <= 0)
			return;
		if (attackObj.Contains<AActor*>(result.GetActor()))
			return;
		attackObj.Add(result.GetActor());
		UGameplayStatics::ApplyPointDamage(result.GetActor(), temp->getDamage(), result.ImpactNormal, result, GetWorld()->GetFirstPlayerController(), GetOwner(), nullptr);
	}
	//

}

