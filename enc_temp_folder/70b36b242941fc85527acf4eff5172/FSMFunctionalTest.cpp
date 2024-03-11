// Fill out your copyright notice in the Description page of Project Settings.


#include "FSMFunctionalTest.h"
#include "CCharacterPlayer.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

AFSMFunctionalTest::AFSMFunctionalTest()
{
	TimeLimit = 5.f;
	//DistanceThresh 거리 계산 액터가 움직일 수 있는 거리 제한
}

void AFSMFunctionalTest::BeginPlay()
{
	Super::BeginPlay();
	controller = GetWorld()->GetFirstPlayerController();
	if (controller)
	{
		Player = CastChecked<ACCharacterPlayer>(controller->GetPawn());
		if (Player)
		{
			/*FinishTest(EFunctionalTestResult::Succeeded, FString("Player is well "));
			UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false);*/
		}
		else
		{
			FinishTest(EFunctionalTestResult::Failed, FString("Controller Null"));
			UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false);
		}
	}
	else
	{
		FinishTest(EFunctionalTestResult::Failed, FString("Null Player Character Reference Pointer"));
		UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false);
	}


	// Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(controller->GetLocalPlayer());

	// PlayerInput = Subsystem->GetPlayerInput();

	// InputAction = Player->getInputAction(TEXT("Jump"));
	///** Get your UInputAction asset from anywhere, likely a UPROPERTY on your blueprint or something */;
	//FInputActionValue ActionValue(1.0f); // This can be a bool, float, FVector2D, or FVector
	//PlayerInput->InjectInputForAction(InputAction, ActionValue);
}

void AFSMFunctionalTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(!one)
	{
		one = true;
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(controller->GetLocalPlayer());

		UEnhancedPlayerInput* PlayerInput = Subsystem->GetPlayerInput();

		UInputAction* InputAction = Player->getInputAction(TEXT("Jump"));
		/** Get your UInputAction asset from anywhere, likely a UPROPERTY on your blueprint or something */;
		FInputActionValue ActionValue(1.0f); // This can be a bool, float, FVector2D, or FVector
		PlayerInput->InjectInputForAction(InputAction, ActionValue);
	}
	if (Player->getCurState() == ECharacterState::JUMP)
	{
		FinishTest(EFunctionalTestResult::Succeeded, FString("FSM work well"));
		UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false);
	}
	/*else
	{
		FinishTest(EFunctionalTestResult::Failed, FString("FSM work well"));
		UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false);
	}*/
}
