// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/PARRING_A.h"
#include "AnimInstance\KwangAnimInstance.h"
#include "CCharacterPlayer.h"
#include "AFSMCollection.h"
#include "FSM/PlayerStateFactory.h"



// Sets default values
APARRING_A::APARRING_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

//TScriptInterface<IIPlayerState> APARRING_A::updateInput(ACCharacterPlayer& player)
//{
//	if (player.GetParringEnd() == true)
//	{
//		return NewObject<ADEFENSELESS_A>();
//	}
//	return nullptr;
//}

void APARRING_A::updateInput()
{

}

void APARRING_A::update()
{
	ctx->Look(ctx->GetLookInputActionValue());
	updateInput();
}

//void APARRING_A::update(ACCharacterPlayer& player)
//{
//	player.Look(player.GetLookInputActionValue());
//}

void APARRING_A::enter()
{
	kwang = ctx->getAnimInstance();
	ctx->PlayAnimMontage(ctx->GetParringMontage(), 1.0f);
	//ctx->SetWaitFrame(30);
	ctx->SetParring(true);
	ctx->SetParringEnd(false);
}

void APARRING_A::exit()
{
	ctx->SetParring(false);
	//ctx->SetWaitFrame(0);
}

void APARRING_A::Destroy()
{
	this->MarkPendingKill();
}

void APARRING_A::InitializeSubState()
{
}

// Called when the game starts or when spawned
void APARRING_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APARRING_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

