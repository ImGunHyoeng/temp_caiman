// Fill out your copyright notice in the Description page of Project Settings.


#include "TEST/FSMTEST.h"
#include "Misc/AutomationTest.h"
#include "CCharacterPlayer.h"
#include "Engine/World.h"


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FFsmTest,"Gameplay.Player.FSM", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FFsmTest::RunTest(const FString& Parameters)
{
	
	
	//UWorld* World = FAutomationTestFramework::GetInstance()-
	UWorld* world = UWorld::CreateWorld(EWorldType::Editor, false);
	//UWorld* world = NewObject<UWorld>(UWorld::StaticClass()); 레벨이 없어서 따로 설정해줘야함.
	check(world!=nullptr&&"World is null")

	ACCharacterPlayer* Player = world->SpawnActor<ACCharacterPlayer>();
	APlayerController* playerController = Player->getPlayerController();
	//playerController.PlayerInput
	
	TestEqual(TEXT("Player init stat idle"), Player->getCurState(), ECharacterState::S_IDLE);
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer());

		UEnhancedPlayerInput* PlayerInput = Subsystem->GetPlayerInput();

		UInputAction* InputAction =Player->getInputAction(TEXT("Jump")); 
		/** Get your UInputAction asset from anywhere, likely a UPROPERTY on your blueprint or something */;
		FInputActionValue ActionValue(1.0f); // This can be a bool, float, FVector2D, or FVector
		PlayerInput->InjectInputForAction(InputAction, ActionValue);
		TestEqual(TEXT("Player jump"), Player->getCurState(), ECharacterState::JUMP);
	}
	Player->Destroy();
	world->DestroyWorld(false);
	return true;
}
FSMTEST::FSMTEST()
{
}

FSMTEST::~FSMTEST()
{
}
