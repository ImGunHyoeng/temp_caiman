// Fill out your copyright notice in the Description page of Project Settings.


#include "CCharacterPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Math/UnrealMathUtility.h"
#include "CMyWeapon.h"
#include "Components/SceneComponent.h"




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

	//static ConstructorHelpers::FObjectFinder<UInputAction> InputActionJumpRef(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/Action/IA_Jump.IA_Jump'"));
	//if (InputActionJumpRef.Object)
	//{
	//	JumpAction = InputActionJumpRef.Object;
	//}

	//static ConstructorHelpers::FObjectFinder<UInputAction> InputActionLookRef(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/Action/IA_Look.IA_Look'"));
	//if (InputActionLookRef.Object)
	//{
	//	LookAction = InputActionLookRef.Object;
	//}

	//static ConstructorHelpers::FObjectFinder<UInputMappingContext> InputMappingRef(TEXT("/Script/EnhancedInput.InputMappingContext'/Game/Input/IMC_Kwang.IMC_Kwang'"));
	//if (InputMappingRef.Object)
	//{
	//	PlayerContext = InputMappingRef.Object;
	//}

	//static ConstructorHelpers::FObjectFinder<UInputAction> InputActionMoveRef(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/Action/IA_Move.IA_Move'"));
	//if (InputActionMoveRef.Object)
	//{
	//	MovementAction = InputActionMoveRef.Object;
	//}

	//static ConstructorHelpers::FObjectFinder<UInputAction> InputActionDrawRef(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/Action/IA_Draw.IA_Draw'"));
	//if (InputActionDrawRef.Object)
	//{
	//	DrawAction = InputActionDrawRef.Object;
	//}

	//static ConstructorHelpers::FObjectFinder<UInputAction> InputActionRunRef(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/Action/IA_Run.IA_Run'"));
	//if (InputActionRunRef.Object)
	//{
	//	RunAction = InputActionRunRef.Object;
	//}

	//static ConstructorHelpers::FObjectFinder<UInputAction> InputActionRollRef(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/Action/IA_Roll.IA_Roll'"));
	//if (InputActionRollRef.Object)
	//{
	//	RollAction = InputActionRollRef.Object;
	//}
	

	currentState = ECharacterState::S_IDLE;
	previousState = ECharacterState::S_IDLE;
	moveSpeed = 1000.0f;
	bSwordDraw = false;
	WaitFrame = 0;
	//bTrigger = false;
	PrimaryActorTick.bCanEverTick = true;
	//inputmapping 과 연결해서 움직이도록 설정 이를 언리얼상에서 매핑으로 해결함
}

void ACCharacterPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	FName WeaponSocket(TEXT("S_Draw"));
	auto CurWeapon = GetWorld()->SpawnActor<ACMyWeapon>(FVector::ZeroVector, FRotator::ZeroRotator);
	if (nullptr != CurWeapon)
	{
		CurWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponSocket);
	}

	APlayerController* PlayerController = CastChecked<APlayerController>(GetController());
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(PlayerContext, 0);
	}
}

void ACCharacterPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Display, TEXT("%d"), currentState);
	UE_LOG(LogTemp, Display, TEXT("%d"), WaitFrame);
	//UE_LOG(LogTemp, Display, TEXT("%f"), GetVelocity().Length());
	//UE_LOG(LogTemp, Warning, TEXT("Bool 값: %s"), bValue ? TEXT("True") : TEXT("False"));
	//UE_LOG(LogTemp, Display, TEXT("Bool 값:%s"), bPressedJump? TEXT("True") : TEXT("False"));
	switch (currentState)
	{
	case ECharacterState::S_IDLE:
		/*if (GetMesh()->GetAnimInstance()->Montage_IsPlaying(AM_Sheath))
			return;
		if(!bTrigger)
			return;
		PlayAnimMontage(AM_Sheath);*/
		//bTrigger = false;
		return;
	case ECharacterState::S_WALK:
		return;
	case ECharacterState::S_RUN:
		return;
	case ECharacterState::JUMP:
	{
		if (bIsAttack)
		{
			currentState = ECharacterState::JUMPATTACK;
			Draw();
			//PlayAnimMontage(AM_Draw);
			WaitFrame = 40;
			bIsJump = false;

			return;
		}
		if (!(GetCharacterMovement()->IsFalling()))
		{
			Landing();
			WaitFrame = 40;
		}
	}
	return;
	case ECharacterState::LANDING:
	{
		WaitFrame--;
		if (WaitFrame == 0)
		{
			SetPrevious();
			currentState = ECharacterState::S_IDLE;
		}
	}
		return;
	case ECharacterState::S_ROLL:
		return;
	case ECharacterState::D_IDLE:
	/*	if (GetMesh()->GetAnimInstance()->Montage_IsPlaying(AM_Draw))
			return;
		if(!bTrigger)
			return;
		PlayAnimMontage(AM_Draw);
		bTrigger = false;*/
		//bTrigger = false;
		return;
	case ECharacterState::D_WALK:
		return;
	case ECharacterState::D_ROLL:
		return;
	case ECharacterState::JUMPATTACK:
	{
		WaitFrame--;
		if (WaitFrame == 0)
		{
			bIsAttack = false;
			SetPrevious();
			currentState = ECharacterState::S_IDLE;
		}
	}
		return;
	case ECharacterState::DEFENSELESS:
		return;
	case ECharacterState::PARRGING:
		return;
	case ECharacterState::ATTACK:
		return;
	}
}


void ACCharacterPlayer::Move(const FInputActionValue& Value)
{
	
	if (currentState!=ECharacterState::S_IDLE&& currentState != ECharacterState::S_WALK && currentState != ECharacterState::S_RUN&& currentState != ECharacterState::D_IDLE&& currentState != ECharacterState::D_WALK)
		return;
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
	if (currentState == ECharacterState::JUMP || currentState == ECharacterState::LANDING)
		return;

	bSwordDraw = !bSwordDraw;
	if (currentState == ECharacterState::JUMPATTACK)
		return;
	if (bSwordDraw)
	{
		SetPrevious();
		currentState = ECharacterState::D_IDLE;
		auto CurWeapon = GetWorld()->SpawnActor<ACMyWeapon>(FVector::ZeroVector, FRotator::ZeroRotator);
		CurWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("S_Sheath"));
	}
	else
	{
		SetPrevious();
		currentState = ECharacterState::S_IDLE;
	}
	//bTrigger = true;
	
}

void ACCharacterPlayer::Run(const FInputActionValue& Value)
{
	if (currentState == ECharacterState::JUMP)
		return;
	if (currentState == ECharacterState::S_WALK)
	{
		SetPrevious();
		GetCharacterMovement()->MaxWalkSpeed = moveSpeed;
		currentState = ECharacterState::S_RUN;
	}
}

void ACCharacterPlayer::Walk(const FInputActionValue& Value)
{
	if (currentState == ECharacterState::JUMP|| currentState == ECharacterState::LANDING||currentState==ECharacterState::JUMPATTACK)
		return;
	if (currentState == ECharacterState::S_IDLE)
	{
		SetPrevious();
		GetCharacterMovement()->MaxWalkSpeed = moveSpeed / 2.0f;
		currentState = ECharacterState::S_WALK;
		return;
	}
	if (currentState == ECharacterState::D_IDLE)
	{
		SetPrevious();
		GetCharacterMovement()->MaxWalkSpeed = moveSpeed / 2.5f;
		currentState = ECharacterState::D_WALK;
	}
}

void ACCharacterPlayer::GoPrevious()
{
	if (currentState == ECharacterState::JUMP|| currentState == ECharacterState::LANDING|| currentState == ECharacterState::JUMPATTACK)
		return;

	currentState = previousState;
	if (currentState != ECharacterState::S_WALK)
		return;
	GetCharacterMovement()->MaxWalkSpeed = moveSpeed / 2.0f;
}

void ACCharacterPlayer::GoIdle(const FInputActionValue& Value)
{
	if (currentState == ECharacterState::JUMP || currentState == ECharacterState::LANDING||currentState == ECharacterState::JUMPATTACK)
		return;
	if (currentState <ECharacterState::D_IDLE)
	{
		currentState = ECharacterState::S_IDLE;
		return;
	}
	currentState = ECharacterState::D_IDLE;


}

void ACCharacterPlayer::Jump()
{
	if (currentState != ECharacterState::S_IDLE && currentState != ECharacterState::S_WALK && currentState != ECharacterState::S_RUN)
		return;
	Super::Jump();
	SetPrevious();
	currentState = ECharacterState::JUMP;
	if (bPressedJump)
		bIsJump = true;
}


void ACCharacterPlayer::Landing()
{
	SetPrevious();
	currentState = ECharacterState::LANDING;
	bIsJump = false;
}

void ACCharacterPlayer::SetPrevious()
{
	previousState = currentState;
}

void ACCharacterPlayer::DoAttack()
{
	if (currentState != ECharacterState::JUMP)
		return;
	bIsAttack = true;
	
}


void ACCharacterPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// InputAction과 InputMappingContext를 연결
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);

	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACCharacterPlayer::Jump);
	//EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACCharacterPlayer::Landing);
	/*EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);*/
	EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered, this, &ACCharacterPlayer::Move);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACCharacterPlayer::Look);
	EnhancedInputComponent->BindAction(DrawAction, ETriggerEvent::Triggered, this, &ACCharacterPlayer::Draw);
	EnhancedInputComponent->BindAction(RollAction, ETriggerEvent::Triggered, this, &ACCharacterPlayer::Draw);
	
	EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Triggered, this, &ACCharacterPlayer::Run);
	EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Completed, this, &ACCharacterPlayer::GoPrevious);
	EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Canceled, this, &ACCharacterPlayer::GoPrevious);
	//트리거가 들어갔을때 아닐때를 인식해서 사용함

	EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered, this, &ACCharacterPlayer::Walk);
	EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Completed, this, &ACCharacterPlayer::GoIdle);


	EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &ACCharacterPlayer::DoAttack);
}





