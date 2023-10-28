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
#include "InputCore.h"





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
	//inputmapping 과 연결해서 움직이도록 설정 이를 언리얼상에서 매핑으로 해결함
}

void ACCharacterPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	FName WeaponSocket(TEXT("S_Draw"));
	Weapon = GetWorld()->SpawnActor<ACMyWeapon>(FVector::ZeroVector, FRotator::ZeroRotator);
	//Weapon->CalculateComponentsBoundingBoxInLocalSpace();
	if (nullptr != Weapon)
	{
		Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponSocket);
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
	//EnhancedInputComponent->set
	UE_LOG(LogTemp, Display, TEXT("%d"), currentState);
	UE_LOG(LogTemp, Display, TEXT("%d"), WaitFrame);
	//UE_LOG(LogTemp, Display, TEXT("%f"), GetVelocity().Length());
	//UE_LOG(LogTemp, Warning, TEXT("Bool 값: %s"), bValue ? TEXT("True") : TEXT("False"));
	//UE_LOG(LogTemp, Display, TEXT("Bool 값:%s"), bPressedJump? TEXT("True") : TEXT("False"));
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();//UGameplayStatics::GetPlayerController(this, 0);
	//PlayerController->GetInputAnalogKeyState(EKeys::SpaceBar);
	//UE_LOG(LogTemp, Display, TEXT("%f"), PlayerController->GetInputAnalogKeyState(EKeys::SpaceBar));

	//PlayerController->GetInputAxisKeyValue(MovementAction->getk);//해당하는 것은 방향성을 가진것만 사용되는 느낌
	//UE_LOG(LogTemp, Display, TEXT("%f"), PlayerController->GetInputAxisKeyValue(EKeys::Up));
	/*PlayerController->GetInputBuffer();
	EnhancedInputComponent->setaction*/
	//float KeyDownTime = PlayerController->GetInputKeyTimeDown(EKeys::SpaceBar);
	//{

	//}
	EnhancedInputComponent->GetActionEventBindings();
	//EnhancedInputComponent->GetActionBinding(0);//.bConsumeInput = false;
	/*EnhancedInputComponent->RemoveActionEventBinding(0);
	EnhancedInputComponent->RemoveActionEventBinding(0);*/
	//바인드 된것과 아닌것을 지우기
	//바인딩된것을 지우는 방식 
	//계속해서 바인딩되고 하기에 쓸모없는 데이터를 낭비하게 된다.
	//이렇게 하지 말고 InputAction의 상태를 가지고 하자

	//MovementAction.
	if(PlayerController->WasInputKeyJustPressed(EKeys::SpaceBar))
	{
		Jump();
	}
	//EnhancedInputComponent
	PlayerContext->get
	switch (currentState)
	{
		
	case ECharacterState::S_IDLE:
		if(GetWorld()->GetFirstPlayerController()->WasInputKeyJustPressed(EKeys::A))
		{
			//Move();
		}
		//Move(EnhancedInputComponent->execOnInputOwnerEndPlayed());
		/*if (GetMesh()->GetAnimInstance()->Montage_IsPlaying(AM_Sheath))
			return;
		if(!bTrigger)
			return;
		PlayAnimMontage(AM_Sheath);*/
		//bTrigger = false;
		return;
	case ECharacterState::S_WALK:
	/*	EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Triggered, this, &ACCharacterPlayer::Run);
		EnhancedInputComponent->GetActionEventBindings();
		EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Completed, this, &ACCharacterPlayer::GoPrevious);
		EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Canceled, this, &ACCharacterPlayer::GoPrevious);*/
		return;
	case ECharacterState::S_RUN:
		//EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Completed, this, &ACCharacterPlayer::GoPrevious);
		//EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Canceled, this, &ACCharacterPlayer::GoPrevious); 
		//EnhancedInputComponent->GetActionEventBindings();
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
			currentState = ECharacterState::D_IDLE;
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
	//if (currentState == ECharacterState::S_IDLE)
	//{
	//	currentState = ECharacterState::S_WALK;
	//}
	//if (currentState == ECharacterState::D_IDLE)
	//{
	//	currentState = ECharacterState::D_WALK;
	//}
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
		Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("S_Sheath"));
	}
	else
	{
		SetPrevious();
		currentState = ECharacterState::S_IDLE;
		Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("S_Draw"));
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
	//UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	//기본 움직임 가능
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACCharacterPlayer::Look);

	//EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACCharacterPlayer::Jump);

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
	//EnhancedInputComponent->bBlockInput = true;
	//밑에 적의 컨트롤러를 달고 있다면 해당하는 키의 작동이 일어나지 않는다.
}





