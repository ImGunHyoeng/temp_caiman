// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/CHARGINGATTACK_A.h"
#include "CCharacterPlayer.h"
#include "FSM/ACTOR_STATE/AFSMCollection.h"
//#include "Animation/Public/Animation.h"

// Sets default values
ACHARGINGATTACK_A::ACHARGINGATTACK_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

TScriptInterface<IIPlayerState> ACHARGINGATTACK_A::updateInput(ACCharacterPlayer& player)
{
	switch (curstate)
	{
	case EChargeAttackState::STAY:
	{
		if (player.getPlayerController()->WasInputKeyJustReleased(EKeys::LeftMouseButton))
		{
			curstate = EChargeAttackState::START;
			resultWaitTime = DoingTime + standardDoing;
			instance->Montage_JumpToSection("ChargeAttackStart");
			player.SetWaitFrame(resultWaitTime);
		}
	}
	break;
	case EChargeAttackState::START:
	{
		
	}
	break;
	case EChargeAttackState::DOING:
	{
		if (player.GetWaitFrame() < 0)
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
			return NewObject<AD_IDLE_A>();
		}
	}
	break;
	default:
		break;
	}
	return NULL;
}

void ACHARGINGATTACK_A::update(ACCharacterPlayer& player)
{
	player.Look(player.GetLookInputActionValue());
	//if(player.getPlayerController()->(EKeys::LeftMouseButton))이건 노티파이
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
		player.Move(player.GetMoveInputActionValue());
		player.WaitFramePassing();
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
}

void ACHARGINGATTACK_A::enter(ACCharacterPlayer& player)
{
	//player.SetNaiagra();
	instance = player.GetMesh()->GetAnimInstance();
	curstate = EChargeAttackState::STAY;
	player.PlayAnimMontage(player.GetChargeAttackMontage(), 1.0f, "ChargingStay");
	DoingTime = 0;
	changeState = false;
}

void ACHARGINGATTACK_A::exit(ACCharacterPlayer& player)
{
	curstate = EChargeAttackState::STAY;
	DoingTime = 0;
	//player.DeActiveNaiagra();
}

void ACHARGINGATTACK_A::Destroy()
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
