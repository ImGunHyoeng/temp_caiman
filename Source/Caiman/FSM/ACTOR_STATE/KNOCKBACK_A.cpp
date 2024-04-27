// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/KNOCKBACK_A.h"
#include "CCharacterPlayer.h"
#include "FSM/PlayerStateFactory.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
AKNOCKBACK_A::AKNOCKBACK_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void AKNOCKBACK_A::updateInput()
{
	if (end)
	{
		ctx->StopAnimMontage();
		currentSuperstate->SwitchState(factory->CreateNORMAL());
	}
}

void AKNOCKBACK_A::update()
{
	ctx->Look(ctx->GetLookInputActionValue());
	updateInput();
}

void AKNOCKBACK_A::enter()
{
	end = false;
}

void AKNOCKBACK_A::InitializeSubState()
{
}

void AKNOCKBACK_A::exit()
{
	end = false;
}

void AKNOCKBACK_A::Destroy()
{
}

void AKNOCKBACK_A::SetPoint(const FVector& ImpactPoint)
{
	ParticlePoint = ImpactPoint;
}

void AKNOCKBACK_A::Start()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ctx->GetHittedParticle(), ParticlePoint);
	FVector forward = GetActorForwardVector();
	FVector hitno_z = FVector(ParticlePoint.X, ParticlePoint.Y, GetActorLocation().Z);
	FVector toHit = (hitno_z - GetActorLocation()).GetSafeNormal();
	float cos = FVector::DotProduct(forward, toHit);
	float seta = acos(cos);
	float degree = FMath::RadiansToDegrees(seta);
	FVector Cross = FVector::CrossProduct(forward, toHit);
	if (Cross.Z < 0)
		degree *= -1;
	//UKismetSystemLibrary::DrawDebugArrow(this, GetActorLocation(), GetActorLocation() + forward * 50, 5, FColor::Red, 15);
	//UKismetSystemLibrary::DrawDebugArrow(this, GetActorLocation(), GetActorLocation() + toHit * 50, 5, FColor::Green, 15);
	//UKismetSystemLibrary::DrawDebugArrow(this, GetActorLocation(), GetActorLocation() + Cross * 50, 5, FColor::Blue, 15);
	FName Section("Back");

	if (degree >= -45.f && degree < 45.f)
	{
		Section = FName("Foward");
	}
	else if (degree >= -135.f && degree < -45.f)
	{
		Section = FName("Left");
	}
	else if (degree >= 45.f && degree < 135.f)
	{
		Section = FName("Right");
	}

	ctx->PlayAnimMontage(ctx->GetHittedMontage(), 1, Section);
}

// Called when the game starts or when spawned
void AKNOCKBACK_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKNOCKBACK_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

