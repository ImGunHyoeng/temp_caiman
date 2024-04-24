// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/NOTHIT_A.h"
#include "FSM/PlayerStateFactory.h"
#include "CCharacterPlayer.h"
// Sets default values
ANOTHIT_A::ANOTHIT_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

TScriptInterface<IIPlayerState> ANOTHIT_A::updateInput(ACCharacterPlayer& player)
{
	return TScriptInterface<IIPlayerState>();
}

void ANOTHIT_A::updateInput()
{

}

void ANOTHIT_A::update(ACCharacterPlayer& player)
{
}

void ANOTHIT_A::update()
{
	updateInput();
}

void ANOTHIT_A::enter(ACCharacterPlayer& player)
{
	InitializeSubState();
}

void ANOTHIT_A::InitializeSubState()
{
	if (ctx->GetMoveInputActionValue().GetMagnitude() < 0.1f)
	{
		SetSubState((factory->CreateS_IDLE()));
	}
	if (ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::SpaceBar))
	{
		SetSubState((factory->CreateJUMP()));
	}
	if (ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::R))
	{
		ctx->Draw();
		SetSubState((factory->CreateDRAWING()));
	}
	if (ctx->GetMoveInputActionValue().GetMagnitude() > 0.1f)
	{
		SetSubState((factory->CreateS_WALK()));
	}
	if (ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::LeftControl))
	{
		ctx->StopMove();
		SetSubState((factory->CreateS_ROLL()));
	}
}

void ANOTHIT_A::exit(ACCharacterPlayer& player)
{
}

void ANOTHIT_A::Destroy()
{
}

// Called when the game starts or when spawned
void ANOTHIT_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANOTHIT_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

