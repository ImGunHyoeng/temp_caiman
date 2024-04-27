// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/ACTOR_STATE/SUPERCHARGINGATTACK_A.h"
#include "CCharacterPlayer.h"

void ASUPERCHARGINGATTACK_A::updateInput()
{
	Super::updateInput();
}

void ASUPERCHARGINGATTACK_A::update()
{
	Super::update();//업데이트에서 이미 진행함. this의 업데이트 input으로 들어가기에 아니다.
}

void ASUPERCHARGINGATTACK_A::enter()
{
	Super::enter();
	ctx->SetNaiagra();
}

void ASUPERCHARGINGATTACK_A::exit()
{
	Super::exit();
	ctx->DeActiveNaiagra();
}

void ASUPERCHARGINGATTACK_A::Destroy()
{
}

void ASUPERCHARGINGATTACK_A::InitializeSubState()
{
}
