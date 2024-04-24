// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/SUPERARMOR_A.h"

// Sets default values
ASUPERARMOR_A::ASUPERARMOR_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

TScriptInterface<IIPlayerState> ASUPERARMOR_A::updateInput(ACCharacterPlayer& player)
{
	return TScriptInterface<IIPlayerState>();
}

void ASUPERARMOR_A::updateInput()
{
}

void ASUPERARMOR_A::update(ACCharacterPlayer& player)
{
}

void ASUPERARMOR_A::update()
{
}

void ASUPERARMOR_A::enter(ACCharacterPlayer& player)
{
}

void ASUPERARMOR_A::InitializeSubState()
{
}

void ASUPERARMOR_A::exit(ACCharacterPlayer& player)
{
}

void ASUPERARMOR_A::Destroy()
{
}

// Called when the game starts or when spawned
void ASUPERARMOR_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASUPERARMOR_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

