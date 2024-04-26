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

//TScriptInterface<IIPlayerState> ADEFENSELESS_A::updateInput(ACCharacterPlayer& player)
//{
//	if (player.GetWaitFrame() < 0)
//	{
//		return NewObject<AD_IDLE_A>();
//	}
//	return nullptr;
//}

void ADEFENSELESS_A::updateInput()
{
	if(ctx->GetDefenseLess()==true)
	{
		SwitchState(factory->CreateD_IDLE());
		return;
	}
}

void ADEFENSELESS_A::update()
{
	//ctx->WaitFramePassing();
	ctx->Look(ctx->GetLookInputActionValue());
	updateInput();

}

//void ADEFENSELESS_A::update(ACCharacterPlayer& player)
//{
//	player.WaitFramePassing();
//	player.Look(player.GetLookInputActionValue());
//}

void ADEFENSELESS_A::enter()
{
	ctx->SetParring(false);
	kwang = ctx->getAnimInstance();
	ctx->PlayAnimMontage(ctx->GetDefenseLessMontage(), 1.0f);
	//if (kwang)
	//	kwang->setDraw();
	//ctx->SetWaitFrame(20);
	ctx->SetDefenseLess(false);
}

void ADEFENSELESS_A::exit()
{
	ctx->SetParringEnd(false);
}

void ADEFENSELESS_A::Destroy()
{
	this->MarkPendingKill();
}

void ADEFENSELESS_A::InitializeSubState()
{
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

