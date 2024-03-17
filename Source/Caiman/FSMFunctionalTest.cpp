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
		Player->setKey(EKeys::SpaceBar);
		Player->SimulateSpaceKeyPress(FName("Jump"));
		bactivateFireInputAction = false;
	}
	
	if (Player->getCurState() == ECharacterState::JUMP)
	{
		//bactivateFireInputAction = true;
		LogMessage(FString("Jump is well"));
		Player->setKey(EKeys::W);
		Player->SimulateSpaceKeyPress(FName("Move"));
	}

	if (Player->getCurState() == ECharacterState::S_WALK)
	{
		//bactivateFireInputAction = true;
		LogMessage(FString("Walk is well"));
	//	UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false);
		Player->setKey(EKeys::W);
		Player->SimulateSpaceKeyPress(FName("Move"));
		Player->setKey(EKeys::LeftShift);
		Player->SimulateSpaceKeyPress(FName("Run"));
	}

	if (Player->getCurState() == ECharacterState::S_RUN)
	{
		//bactivateFireInputAction = true;
		LogMessage(FString("Run is well"));
	//	UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false);
		Player->setKey(EKeys::R);
		Player->SimulateSpaceKeyPress(FName("Draw"));
	}

	if (Player->getCurState() == ECharacterState::D_IDLE)
	{
		//bactivateFireInputAction = true;
		LogMessage(FString("Draw is well"));
		Player->setKey(EKeys::LeftMouseButton);
		Player->SimulateSpaceKeyPress(FName("Attack"));
	}

	if (Player->getCurState() == ECharacterState::ATTACK)
	{
		LogMessage(FString("Attack is well"));
		FinishTest(EFunctionalTestResult::Succeeded, FString("FSM work well"));
		UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false);
	}



}
