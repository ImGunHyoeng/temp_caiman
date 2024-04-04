// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyBase.h"
#include "Components/CapsuleComponent.h"
#include "CCharacterPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/PawnMovementComponent.h"


// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Bone = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh");
	RootComponent = Bone;

	Body = CreateDefaultSubobject<UCapsuleComponent>("Body");
	Body->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	Body->SetupAttachment(Bone);

	DetectEndRange = CreateDefaultSubobject<USphereComponent>("DetectEnd");
	DetectStartRange= CreateDefaultSubobject<USphereComponent>("DetectStart");
	AttackStatrRange = CreateDefaultSubobject<USphereComponent>("AttackStart");
	AttackEndRange = CreateDefaultSubobject<USphereComponent>("AttackEnd");
	
	DetectEndRange->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	DetectEndRange->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	DetectStartRange->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	DetectStartRange->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	AttackEndRange->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	AttackEndRange->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	AttackStatrRange->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	AttackStatrRange->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	DetectEndRange->SetupAttachment(Body);
	DetectStartRange->SetupAttachment(Body);
	AttackEndRange->SetupAttachment(Body);
	AttackStatrRange->SetupAttachment(Body);


	hp = 100;
	Curstate = EEnemyState::STROLL;
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	//충돌처리하는 것과 엮어주는 기능
	
	DetectStartRange->OnComponentBeginOverlap.AddDynamic(this, &AEnemyBase::PlayerInRange);
	DetectEndRange->OnComponentEndOverlap.AddDynamic(this, &AEnemyBase::PlayerOutRange);

	AttackStatrRange->OnComponentBeginOverlap.AddDynamic(this, &AEnemyBase::InAttackRange);
	AttackEndRange->OnComponentEndOverlap.AddDynamic(this, &AEnemyBase::OutAttackRange);
	AttackEndRange->OnComponentEndOverlap.Remove(this, FName("OutAttackRange"));
}

void AEnemyBase::InAttackRange(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Red, FString("ATTACKRANGE_IN"));
	ACCharacterPlayer* target = Cast<ACCharacterPlayer>(OtherActor);
	if (target)
	{
		if(Curstate==EEnemyState::MOVETOWARDPLAYER)
			Curstate = EEnemyState::ATTACK;
	}
}

void AEnemyBase::OutAttackRange(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Red, FString("ATTACKRANGE_OUT"));
	ACCharacterPlayer* target = Cast<ACCharacterPlayer>(OtherActor);
	if (target)
		if(Curstate==EEnemyState::ATTACK)
			Curstate = EEnemyState::MOVETOWARDPLAYER;
}

void AEnemyBase::PlayerInRange(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Curstate == EEnemyState::MOVETOWARDPLAYER)
		return;
	GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Red, FString("DETECT_IN"));
	ACCharacterPlayer* target = Cast<ACCharacterPlayer>(OtherActor);
	if (target)
	{
		player = target;
		Curstate = EEnemyState::MOVETOWARDPLAYER;
	}
}
void AEnemyBase::PlayerOutRange(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Red, FString("DETECT_OUT"));
	ACCharacterPlayer* target = Cast<ACCharacterPlayer>(OtherActor);
	if (target)
	{
		if(Curstate==EEnemyState::MOVETOWARDPLAYER)
			Curstate = EEnemyState::STROLL;
	}
}






// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateInput();
	Update();
}

void AEnemyBase::Update()
{
	if (Curstate == EEnemyState::MOVETOWARDPLAYER)
	{
		FVector PawnLocation = GetActorLocation();

		if (player)
		{
			FVector PlayerLocation = player->GetActorLocation();

			
			FVector MovementDirection = PlayerLocation - PawnLocation;
			MovementDirection.Normalize();
			MovementDirection.Z = 0;

		
			UPawnMovementComponent* MovementComponent = Cast<UPawnMovementComponent>(GetMovementComponent());
			if (MovementComponent) {
				MovementComponent->AddInputVector(MovementDirection);
				//MovementComponent->AddForce(MovementDirection);
			}
		}
		GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Red, FString("MoveTowardPlayer"));
	}

	if (Curstate == EEnemyState::FLEE)
	{
		//hp++;
		FVector PawnLocation = GetActorLocation();

		if (player)
		{
			FVector PlayerForwardVector = player->GetActorForwardVector();
			UPawnMovementComponent* MovementComponent = Cast<UPawnMovementComponent>(GetMovementComponent());
			if (MovementComponent) {
				MovementComponent->AddInputVector(PlayerForwardVector);
			}
		}
		GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Red, FString("FLee"));
	}

	if (Curstate == EEnemyState::STROLL)
	{
		FVector RandomOffset = FMath::VRand();
		RandomOffset.Z = 0.0f; 		
		FVector MovementDirection = GetActorLocation() + RandomOffset;
		UPawnMovementComponent* MovementComponent = Cast<UPawnMovementComponent>(GetMovementComponent());
		if (MovementComponent) 
		{
			float MovementSpeed = 100.0f;
			MovementComponent->AddInputVector(MovementDirection);
		}
		GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Red, FString("Stroll"));
	}

	if (Curstate == EEnemyState::ATTACK)
	{
		GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Red, FString("Attack"));
		//hp--;
	}
	
}

void AEnemyBase::UpdateInput()
{
	if (Curstate == EEnemyState::MOVETOWARDPLAYER)
	{

	}
	if (Curstate == EEnemyState::FLEE)
	{
		if (hp >= 60)
			Curstate = EEnemyState::STROLL;
	}
	if (Curstate == EEnemyState::STROLL)
	{

	}
	if (Curstate == EEnemyState::ATTACK)
	{
		if (hp == 50)
		Curstate = EEnemyState::FLEE;
	}

}

	// Called to bind functionality to input
void AEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

