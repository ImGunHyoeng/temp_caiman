// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/DEFENSELESS_A.h"
#include "AFSMCollection.h"
#include "CCharacterPlayer.h"
#include "AnimInstance\KwangAnimInstance.h"
// Sets default values
ADEFENSELESS_A::ADEFENSELESS_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

TScriptInterface<IIPlayerState> ADEFENSELESS_A::updateInput(ACCharacterPlayer& player)
{
	if (player.GetWaitFrame() < 0)
	{
		return NewObject<AD_IDLE_A>();
	}
	return nullptr;
}

void ADEFENSELESS_A::update(ACCharacterPlayer& player)
{
	player.WaitFramePassing();
	player.Look(player.GetLookInputActionValue());
}

void ADEFENSELESS_A::enter(ACCharacterPlayer& player)
{
	player.SetParring(false);
	kwang = player.getAnimInstance();
	if (kwang)
		kwang->setDraw();
	player.SetWaitFrame(20);
}

void ADEFENSELESS_A::exit(ACCharacterPlayer& player)
{
}

void ADEFENSELESS_A::Destroy()
{
	this->MarkPendingKill();
}

// Called when the game starts or when spawned
void ADEFENSELESS_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADEFENSELESS_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

