// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/OBJECT_STATE/CHARGINGATTACK_O.h"
#include "FSM/PlayerStateFactory.h"
#include "CCharacterPlayer.h"
void UCHARGINGATTACK_O::updateInput()
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
			WaitTime = resultWaitTime;
		}
	}
	break;
	case EChargeAttackState::START:
	{

	}
	break;
	case EChargeAttackState::DOING:
	{
		if (WaitTime < 0)
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

void UCHARGINGATTACK_O::update()
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
		WaitTime -= FApp::GetDeltaTime() * 4;
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

void UCHARGINGATTACK_O::enter()
{
	//player.SetNaiagra();
	instance = ctx->GetMesh()->GetAnimInstance();
	curstate = EChargeAttackState::STAY;
	ctx->PlayAnimMontage(ctx->GetChargeAttackMontage(), 1.0f, "ChargingStay");
	DoingTime = 0;
	changeState = false;
	WaitTime = 0;
}

void UCHARGINGATTACK_O::exit()
{
	curstate = EChargeAttackState::STAY;
	DoingTime = 0;
	WaitTime = 0;
	//player.DeActiveNaiagra();
}

void UCHARGINGATTACK_O::Destroy()
{
}

void UCHARGINGATTACK_O::InitializeSubState()
{
}

void UCHARGINGATTACK_O::ChangeDoing(ACCharacterPlayer* player)
{
	player->PlayAnimMontage(player->GetChargeAttackMontage(), 1.0f, "ChargeAttackLoop");
	//instance->Montage_JumpToSection("ChargeAttackLoop");
	curstate = EChargeAttackState::DOING;
}
