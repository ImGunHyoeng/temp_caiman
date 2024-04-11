// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyBase.h"
#include "Components/CapsuleComponent.h"
#include "CCharacterPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/App.h"
#include "Enemy/EnemyInstance.h"

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

	AttackStatrRange->OnComponentBeginOverlap.AddDynamic(this, &AEnemyBase::InAttackRange);
	targetSet = false;	
	spawnpoint = GetActorLocation();
	//DetectStartRange->OnComponentBeginOverlap.AddDynamic(this, &AEnemyBase::PlayerInRange);
	//DetectEndRange->OnComponentEndOverlap.AddDynamic(this, &AEnemyBase::PlayerOutRange);
	//AttackStatrRange->OnComponentBeginOverlap.AddDynamic(this, &AEnemyBase::InAttackRange);
	//AttackEndRange->OnComponentEndOverlap.AddDynamic(this, &AEnemyBase::OutAttackRange);

	//AttackEndRange->OnComponentEndOverlap.Remove(this, FName("OutAttackRange"));
	enemyaniminstance = Cast<UEnemyInstance>(Bone->GetAnimInstance());
}

void AEnemyBase::InAttackRange(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Red, FString("ATTACKRANGE_IN"));
	ACCharacterPlayer* target = Cast<ACCharacterPlayer>(OtherActor);
	if (target)
	{
		enemyaniminstance->setIsMoveTowardsPlayerEnd();
		enemyaniminstance->setIsAttack();
		Curstate = EEnemyState::ATTACK;
	}
}

//void AEnemyBase::OutAttackRange(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
//{
//	GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Red, FString("ATTACKRANGE_OUT"));
//	ACCharacterPlayer* target = Cast<ACCharacterPlayer>(OtherActor);
//	if (target)
//	{
//		Curstate = EEnemyState::MOVETOWARDPLAYER;
//		AttackEndRange->OnComponentEndOverlap.Remove(this, FName("OutAttackRange"));
//
//		AttackStatrRange->OnComponentBeginOverlap.AddDynamic(this, &AEnemyBase::InAttackRange);
//		
//
//	}	/*if (Curstate == EEnemyState::ATTACK)
//			Curstate = EEnemyState::MOVETOWARDPLAYER;*/
//}
//
//void AEnemyBase::PlayerOutRange(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
//{
//	GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Red, FString("DETECT_OUT"));
//	ACCharacterPlayer* target = Cast<ACCharacterPlayer>(OtherActor);
//	if (target)
//	{
//		Curstate = EEnemyState::STROLL;
//
//	}
//}

void AEnemyBase::PlayerInRange(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Red, FString("DETECT_IN"));
	ACCharacterPlayer* target = Cast<ACCharacterPlayer>(OtherActor);
	if (target)
	{
		player = target;
		targetSet= false;
		enemyaniminstance->setIsMoveTowardsPlayer();
		enemyaniminstance->setStrollEnd();
		Curstate = EEnemyState::MOVETOWARDPLAYER;
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
		return;
	}

	if (Curstate == EEnemyState::FLEE)
	{
		hp += FApp::GetDeltaTime() * 2;
		if (player)
		{
			FVector MovementDirection = GetActorLocation() - player->GetActorLocation();
			MovementDirection.Z = 0;
			FVector PlayerForwardVector = player->GetActorForwardVector();
			UPawnMovementComponent* MovementComponent = Cast<UPawnMovementComponent>(GetMovementComponent());
			if (MovementComponent) {
				MovementComponent->AddInputVector(MovementDirection);
			}
		}
		GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Red, FString("FLee"));
		return;
	}

	if (Curstate == EEnemyState::STROLL)
	{
		if ((GetActorLocation() - spawnpoint).Size() > 4000)
		{
			targetSet = true;
			targetLocation = spawnpoint;
		}//너무 멀어졌다면 스폰 위치로 이동

		if (!targetSet)
		{
			targetLocation = GetActorLocation() + FMath::VRand() * 200;//단위벡터이기에 위치가 사용됨.
			targetSet = true;
		}
		if ((GetActorLocation() - targetLocation).Size() <= 30)
		{
			targetSet = false;
			return;
		}
		targetLocation.Z =GetActorLocation().Z;
		UPawnMovementComponent* MovementComponent = Cast<UPawnMovementComponent>(GetMovementComponent());
		if (MovementComponent)
			MovementComponent->AddInputVector((targetLocation - GetActorLocation()).GetSafeNormal());//단위벡터 값 넣어주기
		GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Red, FString("Stroll"));
		return;
	}

	if (Curstate == EEnemyState::ATTACK)
	{
		GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Red, FString("Attack"));
		//hp--;
		return;
	}
	
}

void AEnemyBase::UpdateInput()
{
	if (Curstate == EEnemyState::MOVETOWARDPLAYER)
	{
		if ((GetActorLocation() - player->GetActorLocation()).Size() >= 900)
		{
			Curstate = EEnemyState::STROLL;
			player = nullptr;

			enemyaniminstance->setIsMoveTowardsPlayerEnd();
			enemyaniminstance->setStroll();
			return;
		}
	}
	if (Curstate == EEnemyState::FLEE)
	{
		if (hp >= 60)
		{
			DetectStartRange->OnComponentBeginOverlap.AddDynamic(this, &AEnemyBase::PlayerInRange);

			AttackStatrRange->OnComponentBeginOverlap.AddDynamic(this, &AEnemyBase::InAttackRange);
			Curstate = EEnemyState::STROLL;
			targetSet = false;
			player = nullptr;
			enemyaniminstance->setIsFleeEnd ();
			enemyaniminstance->setStroll();
			return;
		}
	}
	if (Curstate == EEnemyState::STROLL)
	{

	}
	if (Curstate == EEnemyState::ATTACK)
	{
		if (hp <= 30)
		{
			AttackStatrRange->OnComponentBeginOverlap.Remove(this, FName("InAttackRange"));
			DetectStartRange->OnComponentBeginOverlap.Remove(this, FName("PlayerInRange"));
			enemyaniminstance->setIsFlee();
			enemyaniminstance->setIsAttackEnd();
			Curstate = EEnemyState::FLEE;
			return;
		}		
		if ((GetActorLocation() - player->GetActorLocation()).Size() >= 400)
		{
			enemyaniminstance->setIsMoveTowardsPlayer();
			enemyaniminstance->setIsAttackEnd();
			Curstate = EEnemyState::MOVETOWARDPLAYER;
			return;
		}
	}

}

	// Called to bind functionality to input
void AEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyBase::GetHit_Implementation(const FVector& ImpactPoint)
{
	//DrawDebugSphere(GetWorld(), ImpactPoint, 20, 32, FColor::Red, true);
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HittedParticle, ImpactPoint);
	hp -= 10;
}

