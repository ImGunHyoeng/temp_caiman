// Fill out your copyright notice in the Description page of Project Settings.


#include "CCharacterPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/PlayerInput.h"
#include "Camera/CameraComponent.h"
#include "InputMappingContext.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Math/UnrealMathUtility.h"
#include "CMyWeapon.h"
#include "Components/SceneComponent.h"
#include "InputCore.h"
#include "TimerManager.h"
#include "FSM/IPlayerState.h"
#include "FSM\FSM_Collection.h"
#include "AnimInstance\KwangAnimInstance.h"
#include "Kismet/GameplayStatics.h"








ACCharacterPlayer::ACCharacterPlayer()
{
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));//엔진에 기본적으로 내장되어있는 카메라 요소를 생성 이름도 설정
	CameraBoom->SetupAttachment(RootComponent);//루트 오브젝트에 붙여둠
	CameraBoom->TargetArmLength = 400.0f;//팔길이
	CameraBoom->bUsePawnControlRotation = true;//폰의 회전을 따라서 갈 것인가
	CameraBoom->bInheritPitch = true;
	CameraBoom->bInheritYaw = true;
	CameraBoom->bInheritRoll= false;
	


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);//붙이고 SocketName는 'springarmendpoint'라고 지정되어 있음
	Camera->bUsePawnControlRotation = false;//카메라가 붐에 따라서 간다면 카메라의 회전이 달라짐
	
	
	currentState = ECharacterState::S_IDLE;
	previousState = ECharacterState::S_IDLE;
	moveSpeed = 1000.0f;
	bSwordDraw = false;
	WaitFrame = 0;
	//bTrigger = false;
	PrimaryActorTick.bCanEverTick = true;
}

void ACCharacterPlayer::BeginPlay()
{
	Super::BeginPlay();
	//player키 입력
	
	//KeyMappingArray = PlayerContext->GetMappings();
	FName WeaponSocket(TEXT("S_Sheath"));
	Weapon = GetWorld()->SpawnActor<ACMyWeapon>(FVector::ZeroVector, FRotator::ZeroRotator);
	Weapon->SetActorScale3D(FVector{ 0.35f,0.35f,0.35f });
	//Weapon->CalculateComponentsBoundingBoxInLocalSpace();
	if (nullptr != Weapon)
	{
		Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponSocket);
	}

	PlayerController = CastChecked<APlayerController>(GetController());
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(PlayerContext, 0);
	}
	
	check(EnhancedInputComponent != nullptr&&"you don't allow EnhancedInputComponent");
	//check(bWasInitialized && "Did you forget to call Init()?");
	LateBeginPlay();
	//SimulateSpaceKeyPress(FName("Jump"),EKeys::SpaceBar);
	MoveActionBinding = &EnhancedInputComponent->BindActionValue(MovementAction);
	LookActionBinding = &EnhancedInputComponent->BindActionValue(LookAction);
	playerState = new S_IDLE();

}


void ACCharacterPlayer::SimulateSpaceKeyPress(const FName name)
{
	if (!PlayerController->IsInputKeyDown(key))
	{
		PlayerController->InputKey(key, EInputEvent::IE_Pressed, 1.0f, false);

		FTimerHandle ReleaseHandle;
		FTimerDelegate ReleaseDelegate;

		ReleaseDelegate.BindUObject(this, &ACCharacterPlayer::OnReleaseKey); 
		PlayerController->GetWorldTimerManager().SetTimer(ReleaseHandle, ReleaseDelegate, 2.0f, false);

	}
}

void ACCharacterPlayer::OnReleaseKey() 
{
	PlayerController->InputKey(key, EInputEvent::IE_Released, 1.0f, false);
}
const FInputActionValue ACCharacterPlayer::GetMoveInputActionValue()
{
	return MoveActionBinding->GetValue();
}
const FInputActionValue ACCharacterPlayer::GetLookInputActionValue()
{
	return LookActionBinding->GetValue();
}

IIPlayerState* ACCharacterPlayer::GetCurPlayerState()
{
	 return playerState;
}

UKwangAnimInstance* ACCharacterPlayer::getAnimInstance()
{
	if (GetMesh()->GetAnimInstance())
	{
		UAnimInstance* instance = GetMesh()->GetAnimInstance();
		UKwangAnimInstance* kwang = Cast<UKwangAnimInstance>(instance);
		return kwang;
	}
	return NULL;
}

const TObjectPtr<class ACMyWeapon> ACCharacterPlayer::GetWeapon()
{
	return Weapon;
}
void ACCharacterPlayer::SetKey(FKey _key)
{
	key = _key;
}

void ACCharacterPlayer::changeState(ECharacterState inState)
{
	
	setPreviousState();
	//Destroy(playerState);

	playerState->exit(*this);
	playerState->enter(*this);
	currentState = inState;
}
ECharacterState ACCharacterPlayer::getCurState()
{
	return currentState;
}
void ACCharacterPlayer::setCurState(ECharacterState state)
{
	currentState = state;
}
APlayerController* ACCharacterPlayer::getPlayerController()
{
	return PlayerController;
}


void ACCharacterPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	updateInput();
	update();
}
void ACCharacterPlayer::update()
{
	playerState->update(*this);
}
void ACCharacterPlayer::updateInput()
{
	IIPlayerState* state = playerState->updateInput(*this);
	if (state != NULL)
	{
		playerState->exit(*this);
		playerState->Destroy();
		playerState = state;
		playerState->enter(*this);
	}
}

void ACCharacterPlayer::Move(const FInputActionValue& Value)
{

	FVector2D MovementVector = Value.Get<FVector2D>();


	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);


	AddMovementInput(ForwardDirection, MovementVector.X*moveSpeed);
	AddMovementInput(RightDirection, MovementVector.Y * moveSpeed);
}

void ACCharacterPlayer::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();
	AddControllerYawInput(LookAxisVector.X);
	AddControllerPitchInput(LookAxisVector.Y);
}

void ACCharacterPlayer::Draw()
{
		NoAnimDraw();
		PlayAnimMontage(AM_Draw);
}

void ACCharacterPlayer::NoAnimDraw()
{
	Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("S_Draw"));
}

void ACCharacterPlayer::Sheath()
{
	NoAnimSheath();
	PlayAnimMontage(AM_Sheath);
}

void ACCharacterPlayer::NoAnimSheath()
{
	Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("S_Sheath"));
}

void ACCharacterPlayer::GetHit_Implementation(const FVector& ImpactPoint)
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HittedParticle, ImpactPoint);
}

float ACCharacterPlayer::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float Damage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	return Damage;
}

void ACCharacterPlayer::Hitted(const FVector& ImpactPoint)
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HittedParticle, ImpactPoint);
	FVector forward=GetActorForwardVector();
	FVector hitno_z = FVector(ImpactPoint.X, ImpactPoint.Y, GetActorLocation().Z);
	FVector toHit = (hitno_z - GetActorLocation()).GetSafeNormal();
	float cos = FVector::DotProduct(forward, toHit);
	float seta = acos(cos);
	float degree = FMath::RadiansToDegrees(seta);
	FVector Cross = FVector::CrossProduct(forward, toHit);
	if (Cross.Z < 0)
		degree *= -1;
	UKismetSystemLibrary::DrawDebugArrow(this, GetActorLocation(), GetActorLocation() + forward * 50, 5, FColor::Red,15);
	UKismetSystemLibrary::DrawDebugArrow(this, GetActorLocation(), GetActorLocation() + toHit * 50, 5, FColor::Green,15);
	UKismetSystemLibrary::DrawDebugArrow(this, GetActorLocation(), GetActorLocation() + Cross* 50, 5, FColor::Blue,15);
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

	PlayAnimMontage(AM_Hitted, 1,Section);

}

void ACCharacterPlayer::Run()
{

	if (!PlayerController->WasInputKeyJustPressed(EKeys::LeftShift))
		return;
	{
		setPreviousState();
		GetCharacterMovement()->MaxWalkSpeed = moveSpeed;
		currentState = ECharacterState::S_RUN;
	}
}

void ACCharacterPlayer::Walk()
{
	if (MoveActionBinding->GetValue().GetMagnitude() < 0.1f)
		return;
	if (currentState == ECharacterState::S_IDLE)
	{
		setPreviousState();
		GetCharacterMovement()->MaxWalkSpeed = moveSpeed / 2.0f;
		currentState = ECharacterState::S_WALK;
		return;
	}
	if (currentState == ECharacterState::D_IDLE)
	{
		setPreviousState();
		GetCharacterMovement()->MaxWalkSpeed = moveSpeed / 2.5f;
		currentState = ECharacterState::D_WALK;
	}
}

void ACCharacterPlayer::GoPrevious()
{
	currentState = previousState;
	if (currentState != ECharacterState::S_WALK)
		return;
	GetCharacterMovement()->MaxWalkSpeed = moveSpeed / 2.0f;
}

void ACCharacterPlayer::Jump()
{

	if (!PlayerController->WasInputKeyJustPressed(EKeys::SpaceBar))
		return;
	Super::Jump();
	setPreviousState();
	currentState = ECharacterState::JUMP;
	if (bPressedJump)
		bIsJump = true;
}


void ACCharacterPlayer::Landing()
{
	setPreviousState();
	currentState = ECharacterState::GROUNDED;
	bIsJump = false;
}

void ACCharacterPlayer::setPreviousState()
{
	previousState = currentState;
}

void ACCharacterPlayer::JumpAttack()
{
	if (!PlayerController->WasInputKeyJustPressed(EKeys::LeftMouseButton))
		return;
	bIsJumpAttack = true;
	WaitFrame = 30;
	
}

void ACCharacterPlayer::Attack()
{

	if (!PlayerController->WasInputKeyJustPressed(EKeys::LeftMouseButton))
		return;
	setPreviousState();
	currentState = ECharacterState::ATTACK;
	WaitFrame = 70;
	ComboAttack();
}

void ACCharacterPlayer::Roll()
{
	if (!PlayerController->WasInputKeyJustPressed(EKeys::LeftControl))
		return;
	PlayAnimMontage(AM_Roll);
	if (currentState < ECharacterState::JUMP)
	{
		currentState = ECharacterState::S_ROLL;
		setPreviousState();
		return;
	}
	currentState = ECharacterState::D_ROLL;
	setPreviousState();
}

void ACCharacterPlayer::ComboAttack()
{
	FString a = !bIsCombo ? TEXT("Attack_2_1") : TEXT("Attack_2_2");
	PlayAnimMontage(AM_Attack, 1.0f,FName(*a));
}

void ACCharacterPlayer::AttackCheck()
{
	if (!bWantCombo)
		return;
	bIsCombo = true;
	WaitFrame = 70;
}


void ACCharacterPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// InputAction과 InputMappingContext를 연결
	EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);

	//EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	//기본 움직임 가능
	//EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACCharacterPlayer::Look);

	//EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACCharacterPlayer::Jump);

	//EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered, this, &ACCharacterPlayer::Move);
	//EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACCharacterPlayer::Look);

	//EnhancedInputComponent->BindAction(DrawAction, ETriggerEvent::Triggered, this, &ACCharacterPlayer::Draw);
	//EnhancedInputComponent->BindAction(RollAction, ETriggerEvent::Triggered, this, &ACCharacterPlayer::Draw);
	//
	//EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Triggered, this, &ACCharacterPlayer::Run);
	///*EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Completed, this, &ACCharacterPlayer::GoWalk);
	//EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Canceled, this, &ACCharacterPlayer::GoWalk);*/
	//트리거가 들어갔을때 아닐때를 인식해서 사용함

	//EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered, this, &ACCharacterPlayer::Walk);
	//EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Completed, this, &ACCharacterPlayer::GoIdle);


	//EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &ACCharacterPlayer::DoAttack);
	//EnhancedInputComponent->bBlockInput = true;
	//밑에 적의 컨트롤러를 달고 있다면 해당하는 키의 작동이 일어나지 않는다.
}





