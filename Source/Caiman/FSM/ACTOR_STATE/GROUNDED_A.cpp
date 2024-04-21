// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/GROUNDED_A.h"
#include "AFSMCollection.h"
#include "CCharacterPlayer.h"
#include "AnimInstance\KwangAnimInstance.h"
// Sets default values
AGROUNDED_A::AGROUNDED_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

TScriptInterface<IIPlayerState> AGROUNDED_A::updateInput(ACCharacterPlayer& player)
{
	if (player.GetWaitFrame() <= 0)
	{
		return NewObject<AS_IDLE_A>();
	}
	return nullptr;
}

void AGROUNDED_A::update(ACCharacterPlayer& player)
{
	player.WaitFramePassing();
}

void AGROUNDED_A::enter(ACCharacterPlayer& player)
{
	kwang = player.getAnimInstance();
	player.SetWaitFrame(3);
}

void AGROUNDED_A::exit(ACCharacterPlayer& player)
{
}

void AGROUNDED_A::Destroy()
{
	this->MarkPendingKill();
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

