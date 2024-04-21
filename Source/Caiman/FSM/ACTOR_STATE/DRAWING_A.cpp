// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/DRAWING_A.h"
#include "CCharacterPlayer.h"
#include "AFSMCollection.h"
// Sets default values
ADRAWING_A::ADRAWING_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

TScriptInterface<IIPlayerState> ADRAWING_A::updateInput(ACCharacterPlayer& player)
{
	if (player.GetWaitFrame() <= 0)
	{
		return NewObject<AD_IDLE_A>();
	}
	if (player.GetMoveInputActionValue().GetMagnitude() > 0.1f && player.GetWaitFrame() <= 6)
	{

		player.StopAnimMontage(player.GetDrawMontage());
		player.SetWaitFrame(0);
		return NewObject<AD_IDLE_A>();
	}
	return nullptr;
}

void ADRAWING_A::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
	player.WaitFramePassing();
}

void ADRAWING_A::enter(ACCharacterPlayer& player)
{
	player.SetWaitFrame(8);
}

void ADRAWING_A::exit(ACCharacterPlayer& player)
{
}

void ADRAWING_A::Destroy()
{
	this->MarkPendingKill();
}

// Called when the game starts or when spawned
void ADRAWING_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADRAWING_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

