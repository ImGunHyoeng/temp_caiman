// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/OBJECT_STATE/ATTACK_O.h"
#include "CCharacterPlayer.h"
#include "FSM/PlayerStateFactory.h"

UATTACK_O::UATTACK_O()
{
}

void UATTACK_O::updateInput()
{
	if (changeCharge)
	{
		//super

		//normal
		{
			ctx->PlayAnimMontage(ctx->GetChargeAttackMontage(), 1.0f, FName("ChargingStart"));
			SwitchState(factory->CreateCHARGINGATTACK());
		}

	}
	if (curAttackState == EAttackState::END)
	{
		ctx->StopAnimMontage();
		//ctx->StopAnimMontage();
		//return NewObject<AD_IDLE_O>();
		SwitchState(factory->CreateD_Rest());
	}
}

void UATTACK_O::update()
{
	ctx->Look(ctx->GetLookInputActionValue());
	//DoingTime+=FApp::GetDeltaTime()*60;
	//if (ctx->getPlayerController()->WasInputKeyJustReleased(EKeys::LeftMouseButton))
	//	DoingTime = 0;


	if (curAttackState == EAttackState::DONE)
	{
		if (ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::LeftMouseButton))
		{
			curAttackState = EAttackState::DOING;
			//DoingTime = 100;
			//ctx->SetWaitFrame(60);
			ctx->PlayAnimMontage(ctx->GetAttackMontage(), 1.0f, "Attack_2_2");
		}
	}
	updateInput();
}

void UATTACK_O::enter()
{//DoingTime = 0;
	ctx->SetAttack(true);
	curAttackState = EAttackState::DOING;
	ctx->PlayAnimMontage(ctx->GetAttackMontage(), 1.0f, "Attack_2_1");
	changeCharge = false;
}

void UATTACK_O::exit()
{
	ctx->SetAttack(false);
}

void UATTACK_O::Destroy()
{
}

void UATTACK_O::InitializeSubState()
{
}

void UATTACK_O::ChangeChargeAttack()
{
	changeCharge = true;
}
