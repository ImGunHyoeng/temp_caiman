// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/D_IDLE_A.h"
#include "AFSMCollection.h"
#include "CCharacterPlayer.h"
#include "AnimInstance\KwangAnimInstance.h"
// Sets default values
AD_IDLE_A::AD_IDLE_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

TScriptInterface<IIPlayerState> AD_IDLE_A::updateInput(ACCharacterPlayer& player)
{
	if (!player.GetAttacked())
	{
		if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::R))
		{
			player.Sheath();
			return NewObject<ASHEATHING_A>();
		}
		if (player.GetMoveInputActionValue().GetMagnitude() > 0.1f)
		{
			return NewObject<AD_WALK_A>();
		}
		if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftMouseButton))
		{
			player.SetWaitFrame(70);
			return NewObject<AATTACK_A>();
		}
		if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::Q))
		{
			return NewObject<APARRING_A>();
		}
		if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftControl))
		{
			player.StopMove();
			player.NoAnimSheath();
			return NewObject<AS_ROLL_A>();
		}

	}
	return NULL;
}

void AD_IDLE_A::updateInput()
{
}

void AD_IDLE_A::update()
{
}

void AD_IDLE_A::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
}

void AD_IDLE_A::enter(ACCharacterPlayer& player)
{
	kwang = player.getAnimInstance();
	if (kwang)
		kwang->setDraw();
}

void AD_IDLE_A::exit(ACCharacterPlayer& player)
{
}

void AD_IDLE_A::Destroy()
{
}

void AD_IDLE_A::InitializeSubState()
{
}

// Called when the game starts or when spawned
void AD_IDLE_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AD_IDLE_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

