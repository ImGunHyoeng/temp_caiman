// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/INVINCIBILITY_A.h"

// Sets default values
AINVINCIBILITY_A::AINVINCIBILITY_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

TScriptInterface<IIPlayerState> AINVINCIBILITY_A::updateInput(ACCharacterPlayer& player)
{
	return TScriptInterface<IIPlayerState>();
}

void AINVINCIBILITY_A::updateInput()
{
}

void AINVINCIBILITY_A::update(ACCharacterPlayer& player)
{
}

void AINVINCIBILITY_A::update()
{
}

void AINVINCIBILITY_A::enter(ACCharacterPlayer& player)
{
}

void AINVINCIBILITY_A::InitializeSubState()
{
}

void AINVINCIBILITY_A::exit(ACCharacterPlayer& player)
{
}

void AINVINCIBILITY_A::Destroy()
{
}

// Called when the game starts or when spawned
void AINVINCIBILITY_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AINVINCIBILITY_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

