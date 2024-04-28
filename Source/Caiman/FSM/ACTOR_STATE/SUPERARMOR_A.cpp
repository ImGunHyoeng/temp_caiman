// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/SUPERARMOR_A.h"
#include "FSM/PlayerStateFactory.h"
#include "CCharacterPlayer.h"
// Sets default values
ASUPERARMOR_A::ASUPERARMOR_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

//IIPlayerState* ASUPERARMOR_A::updateInput(ACCharacterPlayer& player)
//{
//	return IIPlayerState*();
//}

void ASUPERARMOR_A::updateInput()
{
	if (end)
	{
		SwitchState(factory->CreateNORMAL());
	}
}

//void ASUPERARMOR_A::update(ACCharacterPlayer& player)
//{
//}

void ASUPERARMOR_A::update()
{
	updateInput();
}

void ASUPERARMOR_A::enter()
{
	InitializeSubState();
	end = false;
}

void ASUPERARMOR_A::InitializeSubState()
{
	//동시에 누르기
	if (ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::LeftMouseButton) && ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::C))
	{
		ctx->PlayAnimMontage(ctx->GetChargeAttackMontage(), 1.0f, FName("ChargingStart"));
		SetSubState(factory->CreateSUPERCHARGINGATTACK());
	}
}

void ASUPERARMOR_A::exit()
{
	end = false;
}

void ASUPERARMOR_A::Destroy()
{
}

// Called when the game starts or when spawned
void ASUPERARMOR_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASUPERARMOR_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

