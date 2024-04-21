// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/S_IDLE_NEWA.h"

// Sets default values
AS_IDLE_NEWA::AS_IDLE_NEWA()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

TScriptInterface<IIPlayerState> AS_IDLE_NEWA::updateInput(ACCharacterPlayer& player)
{
	return nullptr;
}

void AS_IDLE_NEWA::update(ACCharacterPlayer& player)
{
}

void AS_IDLE_NEWA::enter(ACCharacterPlayer& player)
{
}

void AS_IDLE_NEWA::exit(ACCharacterPlayer& player)
{
}

void AS_IDLE_NEWA::Destroy()
{
}

// Called when the game starts or when spawned
void AS_IDLE_NEWA::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AS_IDLE_NEWA::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

