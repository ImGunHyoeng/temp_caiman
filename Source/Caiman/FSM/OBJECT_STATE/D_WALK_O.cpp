// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/OBJECT_STATE/D_WALK_O.h"
#include "CCharacterPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "FSM/PlayerStateFactory.h"

void UD_WALK_O::updateInput()
{
	if (ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::Q))
	{
		ctx->GetCurPlayerState()->SwitchState(factory->CreateINVINCIBILITY());
		return;
	}
	if (ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::LeftControl))
	{
		ctx->StopMove();
		ctx->GetCurPlayerState()->SwitchState(factory->CreateINVINCIBILITY());
		return;
	}
	if (ctx->GetMoveInputActionValue().GetMagnitude() < 0.1f)
	{
		SwitchState(factory->CreateD_IDLE());
	}
	if (ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::LeftMouseButton))
	{
		//ctx->SetWaitFrame(70);
		SwitchState(factory->CreateATTACK());
	}
	if (ctx->getPlayerController()->WasInputKeyJustPressed(EKeys::R))
	{
		ctx->Sheath();
		SwitchState(factory->CreateSHEATHING());
	}
}

void UD_WALK_O::update()
{
	ctx->Move(ctx->GetMoveInputActionValue());
	ctx->Look(ctx->GetLookInputActionValue());
	updateInput();
}

void UD_WALK_O::enter()
{
	ctx->GetCharacterMovement()->MaxWalkSpeed = 1000 / 3.0f;
}

void UD_WALK_O::exit()
{
}

void UD_WALK_O::Destroy()
{
}

void UD_WALK_O::InitializeSubState()
{
}
