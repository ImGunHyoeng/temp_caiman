// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/NORMAL_A.h"
#include "FSM/PlayerStateFactory.h"
#include "CCharacterPlayer.h"
// Sets default values
ANORMAL_A::ANORMAL_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

//TScriptInterface<IIPlayerState> ANORMAL_A::updateInput(ACCharacterPlayer& player)
//{
//	return TScriptInterface<IIPlayerState>();
//}

void ANORMAL_A::updateInput()
{
}

//void ANORMAL_A::update(ACCharacterPlayer& player)
//{
//}

void ANORMAL_A::update()
{
	updateInput();
	
}

void ANORMAL_A::enter()
{
	UE_LOG(LogTemp, Warning, TEXT("Normal"));
	InitializeSubState();
}

void ANORMAL_A::InitializeSubState()
{
	if (ctx->GetParringEnd() == true)
	{
		SetSubState(factory->CreateDEFENSELESS());
		return;
	}
	if (ctx->GetParringSuccessEnd() == true)
	{
		SetSubState(factory->CreateD_IDLE());
		ctx->SetParringSuccessEnd(false);
		return;
	}
	if (ctx->GetSheath())
	{
		SetSubState((factory->CreateS_Rest()));
		//SetSubState((factory->CreateS_IDLE()));
		return;
	}
	if (ctx->GetSheath()==false)
	{
		SetSubState((factory->CreateD_Rest()));
		//SetSubState((factory->CreateD_IDLE()));
		return;
	}
	/*if (ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::SpaceBar))
	{
		SetSubState((factory->CreateJUMP()));
		return;
	}
	if (ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::R))
	{
		ctx->Draw();
		SetSubState((factory->CreateDRAWING()));
		return;
	}
	if (ctx->GetMoveInputActionValue().GetMagnitude() > 0.1f)
	{
		SetSubState((factory->CreateS_WALK()));
		return;
	}*/

}

void ANORMAL_A::exit()
{

}

void ANORMAL_A::Destroy()
{
}

// Called when the game starts or when spawned
void ANORMAL_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANORMAL_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

