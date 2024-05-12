// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InventoryComponent.h"
#include "EnhancedInputSubsystems.h"
#include "HUD/ItemWidget.h"
#include "Item/ItemBase.h"
#include "GameFramework/Character.h"
#include "Misc/OutputDeviceNull.h"
// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UDataTable> ItemDataObject(TEXT("/Game/DATABASE/DT_ItemTable.DT_ItemTable"));
	if (ItemDataObject.Succeeded())
	{
		UE_LOG(LogTemp, Warning, TEXT("DataTable Succeed!"));
		Items = ItemDataObject.Object;
	}
	// ...
}

void UInventoryComponent::ShowInventory()
{
	if (Controller)
	{
		ItemWidget->AddToViewport();
		Controller->SetShowMouseCursor(true);
		FInputModeGameAndUI InputMode;
		InputMode.SetWidgetToFocus(ItemWidget->GetCachedWidget());
		Controller->SetInputMode(InputMode);
	}
}

bool UInventoryComponent::TraceItemToPickUp()
{
	FVector start= Character->GetActorLocation() - FVector(0, 0, 60);
	FVector end = (Character->GetActorLocation() - FVector(0, 0, 60))+ Character->GetActorForwardVector() * 300;
	mySphere = FCollisionShape::MakeSphere(40);
	//DrawDebugCapsule(GetWorld(),(start+end)/2,15)
	GetWorld()->SweepMultiByChannel(outResults, start, end, FQuat::Identity, ECollisionChannel::ECC_PhysicsBody, mySphere);
	for (const auto& result : outResults)
	{
		item = Cast<AItemBase>(result.GetActor());
		if (item)
		{
			UE_LOG(LogTemp, Warning, TEXT("Item name: %s"), *item->Item.ItemID.RowName.ToString());
			return true;
		}	
	}
	return false;
	
	
}

bool UInventoryComponent::AddToInventory(AItemBase* input)
{
	switch (item->Item.type)
	{
	case EItemTypes::Item:
	{
		for (auto & index : allitem.Items)
		{
			//배열상에 해당하는 아이템이 이미 존재하는가
			if (index.ItemID.RowName == input->Item.ItemID.RowName)
			{
				
				FItemDataBase* ItemData = Items->FindRow<FItemDataBase>(input->Item.ItemID.RowName, FString(""));
				if (ItemData)
				{
					if (ItemData->StackSize >= index.Quantity + input->Item.Quantity)
					{
						index.ItemID = input->Item.ItemID;
						index.type = input->Item.type;
						index.Quantity += input->Item.Quantity;
					}
				}
				return true;
			}
		}
		for (auto& index : allitem.Items)
		{
			if (index.Quantity == 0)
			{
				index.ItemID = input->Item.ItemID;
				index.type = input->Item.type;
				index.Quantity += input->Item.Quantity;
				return true;
			}
		}
		return false;
		
		//index.Quantity += input->Item.Quantity;
	}
	default:
		return false;
	}
}


void UInventoryComponent::InteractionKeyDown_Implementation()
{
	if (TraceItemToPickUp())
	{
		if (AddToInventory(item))
		{
			item->Destroy();
			/*FOutputDeviceNull Ar;
			CallFunctionByNameWithArguments(TEXT("UpdateItemsInventoryUI"), Ar, nullptr, true);*/
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
	ItemWidget = CreateWidget<UItemWidget>(GetWorld(), ItemWidgetClass);
	InteractionWidget = CreateWidget<UItemWidget>(GetWorld(), InteractionClass);
	
	UWorld* World = GetWorld();
	if (World)
	{
		Controller = World->GetFirstPlayerController();
	}
	if (Controller)
	{
		Character = Controller->GetCharacter();
	}
	allitem.Armors.SetNum(5);
	allitem.Swords.SetNum(3);//Reserve(3);
	allitem.Items.SetNum(24);
	ShowInventory();

	//ItemWidget=Cast<UItemWidget>(CreateWidget(GetWorld(), ItemWidgetClass));
	
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
	if (!TraceItemToPickUp())
	{
		InteractionWidget->RemoveFromParent();
		return;
	}
	
	InteractionWidget->AddToViewport();
	// ...
}

