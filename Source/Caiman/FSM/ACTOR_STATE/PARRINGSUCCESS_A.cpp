// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/PARRINGSUCCESS_A.h"
#include "AnimInstance\KwangAnimInstance.h"
#include "CCharacterPlayer.h"
#include "AFSMCollection.h"
// Sets default values
APARRINGSUCCESS_A::APARRINGSUCCESS_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

TScriptInterface<IIPlayerState> APARRINGSUCCESS_A::updateInput(ACCharacterPlayer& player)
{
	if (player.GetWaitFrame() < 0)
		return NewObject<AD_IDLE_A>();
	return nullptr;
}

void APARRINGSUCCESS_A::updateInput()
{
}

void APARRINGSUCCESS_A::update()
{
}

void APARRINGSUCCESS_A::update(ACCharacterPlayer& player)
{
	player.WaitFramePassing();
	player.Look(player.GetLookInputActionValue());
}

void APARRINGSUCCESS_A::enter(ACCharacterPlayer& player)
{
	kwang = player.getAnimInstance();
	player.StopAnimMontage();
	player.SetAttacked(true);
	player.PlayAnimMontage(player.GetParringMontage(), 1.0f, FName("Act"));
	player.SetWaitFrame(10);
	player.SetParring(false);
}

void APARRINGSUCCESS_A::exit(ACCharacterPlayer& player)
{
	player.SetAttacked(false);
}

void APARRINGSUCCESS_A::Destroy()
{
	this->MarkPendingKill();
}

void APARRINGSUCCESS_A::InitializeSubState()
{
}

// Called when the game starts or when spawned
void APARRINGSUCCESS_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APARRINGSUCCESS_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

