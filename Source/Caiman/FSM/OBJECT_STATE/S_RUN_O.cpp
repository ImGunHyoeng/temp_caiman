// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/OBJECT_STATE/S_RUN_O.h"
#include "CCharacterPlayer.h"
#include "GameFramework\CharacterMovementComponent.h"
#include "FSM/PlayerStateFactory.h"


void US_RUN_O::updateInput()
{
	if (ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::LeftControl))
	{
		ctx->StopMove();
		ctx->GetCurPlayerState()->SwitchState(factory->CreateINVINCIBILITY());
		return;
	}
	if (ctx->getPlayerController()->WasInputKeyJustReleased(EKeys::LeftShift))
	{
		SwitchState(factory->CreateS_WALK());
		return;
	}
	if (ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::SpaceBar))
	{
		SwitchState(factory->CreateJUMP());
		return;
	}
	if (ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::R))
	{
		ctx->Draw();
		SwitchState(factory->CreateDRAWING());
		return;
	}
}

void US_RUN_O::update()
{
	ctx->Look(ctx->GetLookInputActionValue());

	//set this enter
	ctx->Move(ctx->GetMoveInputActionValue());
	updateInput();
}

void US_RUN_O::enter()
{
	ctx->GetCharacterMovement()->MaxWalkSpeed = 1000;
}

void US_RUN_O::exit()
{
	ctx->GetCharacterMovement()->MaxWalkSpeed = 1000 / 2.0f;
}

void US_RUN_O::InitializeSubState()
{
}

void US_RUN_O::Destroy()
{
}
