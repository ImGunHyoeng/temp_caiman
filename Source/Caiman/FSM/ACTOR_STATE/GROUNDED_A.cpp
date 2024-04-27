// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/GROUNDED_A.h"
#include "AFSMCollection.h"
#include "CCharacterPlayer.h"
#include "AnimInstance\KwangAnimInstance.h"
// Sets default values
AGROUNDED_A::AGROUNDED_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

//TScriptInterface<IIPlayerState> AGROUNDED_A::updateInput()
//{
//	if (player.GetWaitFrame() <= 0)
//	{
//		return NewObject<AS_IDLE_A>();
//	}
//	return nullptr;
//}

void AGROUNDED_A::updateInput()
{
	if (end)
	{
		SwitchState(factory->CreateS_IDLE());
		return;
	}
	if (ctx->GetMoveInputActionValue().GetMagnitude() > 0.1f && canChange)
	{
		SwitchState(factory->CreateS_IDLE());
		return;
	}
}

void AGROUNDED_A::update()
{
	updateInput();

}

//void AGROUNDED_A::update()
//{
//	player.WaitFramePassing();
//}

void AGROUNDED_A::enter()
{
	kwang = ctx->getAnimInstance();
	end = false;
	canChange = false;
}

void AGROUNDED_A::exit()
{
	end = false;
	canChange = false;
}

void AGROUNDED_A::Destroy()
{
	//this->MarkPendingKill();
}

void AGROUNDED_A::InitializeSubState()
{
}

// Called when the game starts or when spawned
void AGROUNDED_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGROUNDED_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

