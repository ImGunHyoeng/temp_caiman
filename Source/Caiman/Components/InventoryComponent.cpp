// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InventoryComponent.h"
#include "EnhancedInputSubsystems.h"
#include "HUD/ItemWidget.h"
// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UInventoryComponent::ShowInventory(const FInputActionValue& Value)
{
	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController* Controller = World->GetFirstPlayerController();
		if (Controller)
		{
			//PlayerOverlay = CreateWidget<UPlayerOverlay>(Controller, PlayerOverlayClass);
			ItemWidget->AddToViewport();
			Controller->SetShowMouseCursor(true);
		}

	}
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetWorld()->GetFirstPlayerController()->GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(PlayerContext, 1);
	}
	ItemWidget=Cast<UItemWidget>(CreateWidget(GetWorld(), ItemWidgetClass));
	
}

//
//void UInventoryComponent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//	EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
//}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

