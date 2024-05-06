// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InputActionValue.h"
#include "DataBase/ItemData.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CAIMAN_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();
	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputMappingContext* PlayerContext;

	UPROPERTY(EditAnywhere, Category ="Money")
	int MoneyAmount;

	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<UUserWidget> ItemWidgetClass;
	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<UUserWidget> InteractionClass;
	UPROPERTY()
	class UItemWidget* ItemWidget;
	UPROPERTY()
	class UItemWidget* InteractionWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FAllItem allitem ;
	//TSharedPtr<class UItemWidget> ItemWidgetPtr;
	void ShowInventory(const FInputActionValue& Value);
	bool TraceItemToPickUp();
	bool AddToInventory(class AItemBase *input);
	void InteractionKeyDown(const FInputActionValue& Value);
	APlayerController* Controller;
	ACharacter* Character;
	TArray<FHitResult> outResults;
	FCollisionShape mySphere;
	class AItemBase* item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UDataTable* Items;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
