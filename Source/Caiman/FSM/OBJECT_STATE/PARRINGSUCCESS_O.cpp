// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/OBJECT_STATE/PARRINGSUCCESS_O.h"
#include "AnimInstance\KwangAnimInstance.h"
#include "CCharacterPlayer.h"
#include "FSM/PlayerStateFactory.h"


void UPARRINGSUCCESS_O::updateInput()
{
	if (end)
	{
		ctx->SetParringSuccessEnd(true);
		return;
	}
}

void UPARRINGSUCCESS_O::update()
{
	ctx->Look(ctx->GetLookInputActionValue());
	updateInput();
}

void UPARRINGSUCCESS_O::enter()
{
	kwang = ctx->getAnimInstance();
	ctx->StopAnimMontage();
	ctx->SetAttacked(true);
	ctx->PlayAnimMontage(ctx->GetParringMontage(), 1.0f, FName("Act"));
	//ctx->SetWaitFrame(10);
	ctx->SetParring(false);
	ctx->SetParringSuccessEnd(false);
	end = false;
}

void UPARRINGSUCCESS_O::exit()
{
	ctx->SetAttacked(false);
	ctx->SetParringSuccessEnd(false);
	end = false;
}

void UPARRINGSUCCESS_O::Destroy()
{
}

void UPARRINGSUCCESS_O::InitializeSubState()
{
}
