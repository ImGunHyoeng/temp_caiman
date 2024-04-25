// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/INVINCIBILITY_A.h"
#include "AnimInstance\KwangAnimInstance.h"
#include "CCharacterPlayer.h"
#include "AFSMCollection.h"
#include "FSM/PlayerStateFactory.h"

// Sets default values
AINVINCIBILITY_A::AINVINCIBILITY_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

//TScriptInterface<IIPlayerState> AINVINCIBILITY_A::updateInput(ACCharacterPlayer& player)
//{
//	return TScriptInterface<IIPlayerState>();
//}

void AINVINCIBILITY_A::updateInput()
{
	if (ctx->GetParringEnd() == true)
	{
		SwitchState(factory->CreateNORMAL());
		return;
	}

}

void AINVINCIBILITY_A::update()
{
	updateInput();
	
}

void AINVINCIBILITY_A::enter()
{

	InitializeSubState();
}

void AINVINCIBILITY_A::InitializeSubState()
{
	if (ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::LeftControl))
	{
		ctx->StopMove();
		SetSubState(factory->CreateS_ROLL());
		return;
	}
	if (ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::Q))
	{
		SetSubState(factory->CreatePARRING());
		return;
	}
}

void AINVINCIBILITY_A::exit()
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
