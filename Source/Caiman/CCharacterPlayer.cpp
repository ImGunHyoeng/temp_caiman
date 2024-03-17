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
void ACCharacterPlayer::setKey(FKey _key)
{
	key = _key;
}
void ACCharacterPlayer::updateInput()
{

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

void ACCharacterPlayer::update()
{
	Look(LookActionBinding->GetValue());
	switch (currentState)
	{
	case ECharacterState::S_IDLE:
	{
		Move(MoveActionBinding->GetValue());
		Jump();
		Walk();
		Draw();
		return;
	}
	case ECharacterState::S_WALK:
	{
		Move(MoveActionBinding->GetValue());
		Run();
		GoIdle();
		return;
	}
	case ECharacterState::S_RUN:
	{
		Move(MoveActionBinding->GetValue());
		//Look(LookActionBinding->GetValue());
		Jump();
		Roll();
		GoWalk();
		Draw();
		return;
	}
	case ECharacterState::JUMP:
	{
		//Look(LookActionBinding->GetValue());
		JumpAttack();
		if (bIsJumpAttack)
		{
			NoAnimDraw();
			SetPrevious();
			currentState = ECharacterState::JUMPATTACK;
			//PlayAnimMontage(AM_Draw);
			WaitFrame = 50;
			bIsJump = false;
			return;
		}
		if (!(GetCharacterMovement()->IsFalling()))
		{
			Landing();
			WaitFrame = 40;
		}
		return;
	}
	case ECharacterState::GROUNDED:
	{
		WaitFrame--;
		if (WaitFrame == 0)
		{
			SetPrevious();
			currentState = ECharacterState::S_IDLE;
		}
		return;
	}
	case ECharacterState::S_ROLL:
	{
		return;
	}
	case ECharacterState::D_IDLE:
	{
		Move(MoveActionBinding->GetValue());
		Look(LookActionBinding->GetValue());
		Walk();
		Draw();
		Attack();
		return;
	}
	case ECharacterState::D_WALK:
		//Walk();
	{
		Move(MoveActionBinding->GetValue());
		GoIdle();
		Attack();
		return;
	}
	case ECharacterState::D_ROLL:
	{
		return;
	}
	case ECharacterState::JUMPATTACK:
	{
		//점프
		WaitFrame--;
		if (WaitFrame == 0)
		{
			bIsJumpAttack = false;
			SetPrevious();
			currentState = ECharacterState::D_IDLE;
		}
		return;
	}
	case ECharacterState::DEFENSELESS:
		return;
	case ECharacterState::PARRGING:
		return;
	case ECharacterState::ATTACK:
	{
		if (PlayerController->WasInputKeyJustPressed(EKeys::LeftMouseButton))
			bWantCombo = true;
		if (bIsCombo)
		{
			//Attack_BP();
			ComboAttack();
			bIsCombo = false;
		}
		if (WaitFrame == 0)
		{
			SetPrevious();
			currentState = ECharacterState::D_IDLE;
			bWantCombo = false;
		}
		WaitFrame--;
		//UE_LOG(LogTemp, Warning, TEXT("bWantCombo:%s"), bWantCombo ? TEXT("True") : TEXT("False"));
		return;
	}
	}
}
void ACCharacterPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	update();
	
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
	

	if (!PlayerController->WasInputKeyJustPressed(EKeys::R))
		return;
		//bSwordDraw = !bSwordDraw;
		NoAnimDraw();
		SetPrevious();
	if (bSwordDraw)
	{
		currentState = ECharacterState::D_IDLE;
		/*SetPrevious();
		currentState = ECharacterState::D_IDLE;
		Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("S_Draw")); */
		PlayAnimMontage(AM_Draw);
		//AM_Draw->Notifies
	}
	else
	{
		currentState = ECharacterState::S_IDLE;
		/*SetPrevious();
		currentState = ECharacterState::S_IDLE;
		Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("S_Sheath"));*/
		PlayAnimMontage(AM_Sheath);
	}
	//bTrigger = true;
	
}

void ACCharacterPlayer::NoAnimDraw()
{
	bSwordDraw = !bSwordDraw;
	if (bSwordDraw)
	{
		Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("S_Draw"));
	}
	else
	{
		Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("S_Sheath"));
	}
}

void ACCharacterPlayer::Run()
{

	if (!PlayerController->WasInputKeyJustPressed(EKeys::LeftShift))
		return;
	{
		SetPrevious();
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
	currentState = previousState;
	if (currentState != ECharacterState::S_WALK)
		return;
	GetCharacterMovement()->MaxWalkSpeed = moveSpeed / 2.0f;
}

void ACCharacterPlayer::GoWalk()
{
	//해당하는 것은 릴리즈와 트리거 cancled와 같은 상태를 처리할때 사용함
	if (!PlayerController->WasInputKeyJustReleased(EKeys::LeftShift))
		return;
	SetPrevious();
	currentState = ECharacterState::S_WALK;
	GetCharacterMovement()->MaxWalkSpeed = moveSpeed / 2.0f;
}

void ACCharacterPlayer::GoIdle()
{
	FVector2D moveValue = FMath::Square<FVector2D>(MoveActionBinding->GetValue().Get<FVector2D>());
	//MoveActionBinding->GetValue().GetMagnitude();//해당하는 값을 제곱해주는 것

	if (MoveActionBinding->GetValue().GetMagnitude() > 0.1f)
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

	if (!PlayerController->WasInputKeyJustPressed(EKeys::SpaceBar))
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
	currentState = ECharacterState::GROUNDED;
	bIsJump = false;
}

void ACCharacterPlayer::SetPrevious()
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
	SetPrevious();
	currentState = ECharacterState::ATTACK;
	WaitFrame = 70;
	//Attack_BP();
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
		SetPrevious();
		return;
	}
	currentState = ECharacterState::D_ROLL;
	SetPrevious();
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





