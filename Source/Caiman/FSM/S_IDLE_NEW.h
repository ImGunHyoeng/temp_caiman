// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "UObject/NoExportTypes.h"
#include "IPlayerState.h"
#include "S_IDLE_NEW.generated.h"

/**
 * 
 */
UCLASS()
class CAIMAN_API US_IDLE_NEW : public UObject,public IIPlayerState
{
	GENERATED_BODY()
public:
	US_IDLE_NEW() {}
	virtual IIPlayerState* updateInput(class ACCharacterPlayer& player) ;
	
	
	virtual void update(class ACCharacterPlayer& player) ;
	virtual void updatechild(class ACCharacterPlayer& player);
	virtual void enter(class ACCharacterPlayer& player) ;
	virtual void exit(class ACCharacterPlayer& player) ;
	virtual void Destroy();

};
