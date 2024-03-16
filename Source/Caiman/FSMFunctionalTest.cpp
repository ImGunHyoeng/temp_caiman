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
			Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(controller->GetLocalPlayer());

			PlayerInput = Subsystem->GetPlayerInput();

			//InputAction = Player->getInputAction(TEXT("Jump"));
			bactivateFireInputAction = true;
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
}

void AFSMFunctionalTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bactivateFireInputAction)
	{
		Player->SimulateSpaceKeyPress(FName("Jump"), EKeys::SpaceBar);
		//FInputActionValue ActionValue(1.0f); // This can be a bool, float, FVector2D, or FVector
		//PlayerInput->InjectInputForAction(InputAction, ActionValue);
		bactivateFireInputAction = false;
	}
	
	if (Player->getCurState() == ECharacterState::JUMP)
	{
		bactivateFireInputAction = true;
		//LogMessage(FString("Jump is well"));
		FinishTest(EFunctionalTestResult::Succeeded, FString("FSM work well"));
		UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false);
		//InputAction = Player->getInputAction(TEXT("Move"));
	}

	if (Player->getCurState() == ECharacterState::S_WALK)
	{
		bactivateFireInputAction = true;
		LogMessage(FString("Walk is well"));
	//	UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false);
		InputAction = Player->getInputAction(TEXT("Run"));
	}

	if (Player->getCurState() == ECharacterState::S_RUN)
	{
		bactivateFireInputAction = true;
		LogMessage(FString("Run is well"));
	//	UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false);
		InputAction = Player->getInputAction(TEXT("Draw"));
	}

	if (Player->getCurState() == ECharacterState::D_IDLE)
	{
		bactivateFireInputAction = true;
		LogMessage(FString("Draw is well"));
	//	UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false);
		InputAction = Player->getInputAction(TEXT("Attack"));
	}

	if (Player->getCurState() == ECharacterState::ATTACK)
	{
		LogMessage(FString("Attack is well"));
		FinishTest(EFunctionalTestResult::Succeeded, FString("FSM work well"));
		UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false);
	}



}
