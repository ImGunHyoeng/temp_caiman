// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/S_IDLE_NEW.h"

TScriptInterface<IIPlayerState> US_IDLE_NEW::updateInput(ACCharacterPlayer& player)
{
	return nullptr;
}

void US_IDLE_NEW::update(ACCharacterPlayer& player)
{
	updatechild(player);
}

void US_IDLE_NEW::updatechild(ACCharacterPlayer& player)
{
	this->updatechild(player);
}

void US_IDLE_NEW::enter(ACCharacterPlayer& player)
{
}

void US_IDLE_NEW::exit(ACCharacterPlayer& player)
{
}

void US_IDLE_NEW::Destroy()
{
}
