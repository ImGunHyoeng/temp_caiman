// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "UObject/NoExportTypes.h"
#include "FSM/IPlayerState.h"
#include "ATTACK_O.generated.h"


//UENUM()
//enum class EAttackState :uint8
//{
//	END
//	, DONE
//	, DOING
//};
/**
 * 
 */
UCLASS()
class CAIMAN_API UATTACK_O : public UObject , public IIPlayerState
{
	GENERATED_BODY()
	
public:
	virtual TScriptInterface<IIPlayerState> updateInput(class ACCharacterPlayer& player);
	virtual void update(class ACCharacterPlayer& player);
	virtual void updateInput() {}
	virtual void enter(class ACCharacterPlayer& player);
	virtual void exit(class ACCharacterPlayer& player);
	virtual void Destroy();

	//UFUNCTION(BlueprintCallable)
	//void AttackStateEnd() { curAttackState = EAttackState::END; }
	//UFUNCTION(BlueprintCallable)
	//void AttackStateDone() { curAttackState = EAttackState::DONE; }
	//UFUNCTION(BlueprintCallable)
	//void AttackStateDoing() { curAttackState = EAttackState::DOING; }
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//EAttackState curAttackState;


	//int DoingTime;
};
