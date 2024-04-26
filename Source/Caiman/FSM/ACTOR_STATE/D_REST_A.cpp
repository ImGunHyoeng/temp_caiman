// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/D_REST_A.h"
#include "FSM/PlayerStateFactory.h"
#include "CCharacterPlayer.h"

// Sets default values
AD_REST_A::AD_REST_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AD_REST_A::updateInput()
{
	if (IsEnd)
	{
		SwitchState(factory->CreateD_IDLE());
	}
}

void AD_REST_A::update()
{
	updateInput();
}

void AD_REST_A::enter()
{
	ctx->PlayAnimMontage(ctx->GetD_RestMontage(), 1.0f);
	IsEnd = false;
}

void AD_REST_A::InitializeSubState()
{
}

void AD_REST_A::exit()
{
}

void AD_REST_A::Destroy()
{
}

// Called when the game starts or when spawned
void AD_REST_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AD_REST_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

