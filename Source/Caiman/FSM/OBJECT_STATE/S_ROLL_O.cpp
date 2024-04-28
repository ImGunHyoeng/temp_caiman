// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/OBJECT_STATE/S_ROLL_O.h"
#include "AnimInstance\KwangAnimInstance.h"
#include "CCharacterPlayer.h"
#include "OFSMCollection.h"
#include "FSM/PlayerStateFactory.h"

void US_ROLL_O::updateInput()
{
	if (end)
	{
		ctx->StopAnimMontage();
		ctx->GetCurPlayerState()->SwitchState(factory->CreateNORMAL());
		return;
	}
}

void US_ROLL_O::update()
{
	if (isRoll)
		ctx->AddMovementInput(ctx->GetActorForwardVector(), 5);
	ctx->Look(ctx->GetLookInputActionValue());
	updateInput();
}

void US_ROLL_O::enter()
{
	kwang = ctx->getAnimInstance();
	isRoll = true;
	ctx->PlayAnimMontage(ctx->GetRollMontage(), 1.0f, input);
	end = false;
}

void US_ROLL_O::exit()
{
	isRoll = true;
	end = false;
}

void US_ROLL_O::Destroy()
{
}

void US_ROLL_O::InitializeSubState()
{
}
