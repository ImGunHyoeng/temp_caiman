// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/S_REST_A.h"
#include "FSM/PlayerStateFactory.h"
#include "CCharacterPlayer.h"

// Sets default values
AS_REST_A::AS_REST_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void AS_REST_A::updateInput()
{
	if (IsEnd)
	{
		ctx->StopAnimMontage();
		SwitchState(factory->CreateS_IDLE());
	}
}

void AS_REST_A::update()
{
	updateInput();
}

void AS_REST_A::enter()
{
	ctx->PlayAnimMontage(ctx->GetS_RestMontage(), 1.0f);
	IsEnd = false;
}

void AS_REST_A::InitializeSubState()
{
}

void AS_REST_A::exit()
{
	IsEnd = false;
}

void AS_REST_A::Destroy()
{
}



// Called when the game starts or when spawned
void AS_REST_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AS_REST_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

