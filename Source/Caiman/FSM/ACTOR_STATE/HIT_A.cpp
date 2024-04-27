// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/HIT_A.h"
#include "FSM/PlayerStateFactory.h"
// Sets default values
AHIT_A::AHIT_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

//TScriptInterface<IIPlayerState> AHIT_A::updateInput(ACCharacterPlayer& player)
//{
//	return TScriptInterface<IIPlayerState>();
//}

void AHIT_A::updateInput()
{
}

//void AHIT_A::update(ACCharacterPlayer& player)
//{
//}

void AHIT_A::update()
{
}

void AHIT_A::enter()
{
	InitializeSubState();
}

void AHIT_A::InitializeSubState()
{
	SetSubState(factory->CreateKNOCKBACK());
}

void AHIT_A::exit()
{
}

void AHIT_A::Destroy()
{
}

// Called when the game starts or when spawned
void AHIT_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHIT_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

