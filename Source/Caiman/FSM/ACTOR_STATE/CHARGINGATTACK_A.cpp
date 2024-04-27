// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/CHARGINGATTACK_A.h"
#include "CCharacterPlayer.h"
#include "FSM/ACTOR_STATE/AFSMCollection.h"
//#include "Animation/Public/Animation.h"

// Sets default values
ACHARGINGATTACK_A::ACHARGINGATTACK_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

//TScriptInterface<IIPlayerState> ACHARGINGATTACK_A::updateInput(ACCharacterPlayer& player)
//{
//	switch (curstate)
//	{
//	case EChargeAttackState::STAY:
//	{
//		if (player.getPlayerController()->WasInputKeyJustReleased(EKeys::LeftMouseButton))
//		{
//			curstate = EChargeAttackState::START;
//			resultWaitTime = DoingTime + standardDoing;
//			instance->Montage_JumpToSection("ChargeAttackStart");
//			player.SetWaitFrame(resultWaitTime);
//		}
//	}
//	break;
//	case EChargeAttackState::START:
//	{
//		
//	}
//	break;
//	case EChargeAttackState::DOING:
//	{
//		if (player.GetWaitFrame() < 0)
//		{
//			curstate = EChargeAttackState::DONE;
//			instance->Montage_JumpToSection("ChargeAttackEnd");
//		}
//	}
//	break;
//	case EChargeAttackState::DONE:
//	{
//		if (changeState)
//		{
//			return NewObject<AD_IDLE_A>();
//		}
//	}
//	break;
//	default:
//		break;
//	}
//	return NULL;
//}

void ACHARGINGATTACK_A::updateInput()
{
	switch (curstate)
	{
	case EChargeAttackState::STAY:
	{
		if (ctx->getPlayerController()->WasInputKeyJustReleased(EKeys::LeftMouseButton))
		{
			curstate = EChargeAttackState::START;
			resultWaitTime = DoingTime + standardDoing;
			instance->Montage_JumpToSection("ChargeAttackStart");
			WaitTime=resultWaitTime;
		}
	}
	break;
	case EChargeAttackState::START:
	{

	}
	break;
	case EChargeAttackState::DOING:
	{
		if (WaitTime<0)
		{
			curstate = EChargeAttackState::DONE;
			instance->Montage_JumpToSection("ChargeAttackEnd");
		}
	}
	break;
	case EChargeAttackState::DONE:
	{
		if (changeState)
		{
			SwitchState(factory->CreateD_IDLE());
		}
	}
	break;
	default:
		break;
	}
}

void ACHARGINGATTACK_A::update()
{
	ctx->Look(ctx->GetLookInputActionValue());
	//if(ctx->getPlayerController()->(EKeys::LeftMouseButton))이건 노티파이
	switch (curstate)
	{
	case EChargeAttackState::STAY:
	{

		DoingTime += FApp::GetDeltaTime() * 2;
		DoingTime = FMath::Clamp(DoingTime, 0, ExtraTimeLimit);

	}
	break;
	case EChargeAttackState::START:
	{

	}
	break;
	case EChargeAttackState::DOING:
	{
		ctx->Move(ctx->GetMoveInputActionValue());
		WaitTime -= FApp::GetDeltaTime()*4;
		/*	if(!player.GetMesh()->GetAnimInstance()->Montage_IsPlaying(NULL))
				player.PlayAnimMontage(player.GetChargeAttackMontage(), 1.0f, "ChargeAttackLoop");*/
				//이런식으로 현재 몽타주가 플레이 중인지 확인하고 값을 가져와준다.
				/*GetMesh()->GetAnimInstance()->Montage_IsPlaying(NULL)
				//UAnimMontage::isplay*/

	}
	break;
	case EChargeAttackState::DONE:
	{

	}
	break;
	default:
		break;
	}
	updateInput();

}

void ACHARGINGATTACK_A::enter()
{
	//player.SetNaiagra();
	instance = ctx->GetMesh()->GetAnimInstance();
	curstate = EChargeAttackState::STAY;
	ctx->PlayAnimMontage(ctx->GetChargeAttackMontage(), 1.0f, "ChargingStay");
	DoingTime = 0;
	changeState = false;
	WaitTime = 0;
}

void ACHARGINGATTACK_A::exit()
{
	curstate = EChargeAttackState::STAY;
	DoingTime = 0;
	WaitTime = 0;
	//player.DeActiveNaiagra();
}

void ACHARGINGATTACK_A::Destroy()
{

}

void ACHARGINGATTACK_A::InitializeSubState()
{
}

void ACHARGINGATTACK_A::ChangeDoing(ACCharacterPlayer* player)
{
	player->PlayAnimMontage(player->GetChargeAttackMontage(), 1.0f, "ChargeAttackLoop");
	//instance->Montage_JumpToSection("ChargeAttackLoop");
	curstate = EChargeAttackState::DOING;
}

// Called when the game starts or when spawned
void ACHARGINGATTACK_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACHARGINGATTACK_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

