// Copyright Epic Games, Inc. All Rights Reserved.


#include "CaimanGameModeBase.h"

ACaimanGameModeBase::ACaimanGameModeBase()
{
	static ConstructorHelpers::FClassFinder<APawn> DefaultPawnRef(TEXT("/Game/Blueprints/BP_CCharacter.BP_CCharacter_C"));
	if (DefaultPawnRef.Class)
	{
		DefaultPawnClass = DefaultPawnRef.Class;//GameModeBase에 이미 정의 되어있기에 정의 안해도 사용 가능함
	}

	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerClassRef(TEXT("/Script/CoreUObject.Class'/Script/Caiman.CPlayerController'"));
	if (PlayerControllerClassRef.Class)
	{
		PlayerControllerClass = PlayerControllerClassRef.Class;
	}

	
}
