// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/PARRINGSUCCESS_A.h"
#include "AnimInstance\KwangAnimInstance.h"
#include "CCharacterPlayer.h"
#include "AFSMCollection.h"
#include "FSM/PlayerStateFactory.h"

// Sets default values
APARRINGSUCCESS_A::APARRINGSUCCESS_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

//TScriptInterface<IIPlayerState> APARRINGSUCCESS_A::updateInput(ACCharacterPlayer& player)
//{
//	if (player.GetWaitFrame() < 0)
//		return NewObject<AD_IDLE_A>();
//	return nullptr;
//}

void APARRINGSUCCESS_A::updateInput()
{
	if (ctx->GetWaitFrame() < 0)
	{
		SwitchState(factory->CreateD_IDLE());
		return;
	}
}

void APARRINGSUCCESS_A::update()
{
	ctx->WaitFramePassing();
	ctx->Look(ctx->GetLookInputActionValue());
	updateInput();

}

//void APARRINGSUCCESS_A::update(ACCharacterPlayer& player)
//{
//	player.WaitFramePassing();
//	player.Look(player.GetLookInputActionValue());
//}

void APARRINGSUCCESS_A::enter()
{
	kwang = ctx->getAnimInstance();
	ctx->StopAnimMontage();
	ctx->SetAttacked(true);
	ctx->PlayAnimMontage(ctx->GetParringMontage(), 1.0f, FName("Act"));
	ctx->SetWaitFrame(10);
	ctx->SetParring(false);
}

void APARRINGSUCCESS_A::exit()
{
	ctx->SetAttacked(false);
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

