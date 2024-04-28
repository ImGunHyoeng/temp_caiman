// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/JUMP_A.h"
#include "CCharacterPlayer.h"
#include "AFSMCollection.h"
#include "GameFramework\CharacterMovementComponent.h"
#include "AnimInstance/KwangAnimInstance.h"
// Sets default values
AJUMP_A::AJUMP_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

//IIPlayerState* AJUMP_A::updateInput(ACCharacterPlayer& ctx->
//{
//	if (player.getPlayerController()->WasInputKeyJustPressed(EKeys::LeftMouseButton))
//	{
//		player.NoAnimDraw();
//		player.SetWaitFrame(6);
//		return NewObject<AJUMPATTACK_A>();
//	}
//	if (!(player.GetCharacterMovement()->IsFalling()))
//	{
//		return NewObject<AGROUNDED_A>();
//	}
//	return nullptr;
//}

void AJUMP_A::updateInput()
{
	if (ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::LeftMouseButton))
	{
		ctx->NoAnimDraw();
		//return NewObject<AJUMPATTACK_A>();
		SwitchState(factory->CreateJUMPATTACK());
		return;
	}
	if (!(ctx->GetCharacterMovement()->IsFalling()))
	{
		//return NewObject<AGROUNDED_A>();
		SwitchState(factory->CreateGROUNDED());
		return;
	}
}

void AJUMP_A::update()
{
	ctx->Look(ctx->GetLookInputActionValue());
	updateInput();

}

//void AJUMP_A::update(ACCharacterPlayer& player)
//{
//	player.Look(player.GetLookInputActionValue());
//}

void AJUMP_A::enter()
{
	kwang = ctx->getAnimInstance();
	if (kwang)
		kwang->setJump();
	ctx->Super::Jump();
}

void AJUMP_A::exit()
{
	if (kwang)
		kwang->setJumpEnd();
}

void AJUMP_A::Destroy()
{
	//this->MarkPendingKill();
}

void AJUMP_A::InitializeSubState()
{
}

// Called when the game starts or when spawned
void AJUMP_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJUMP_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

