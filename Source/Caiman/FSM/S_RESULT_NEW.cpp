// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/S_RESULT_NEW.h"

US_RESULT_NEW::US_RESULT_NEW()
{

}

void US_RESULT_NEW::updatechild(ACCharacterPlayer& player)
{
	UE_LOG(LogTemp, Warning, TEXT("Result_new_Operate"));
}

IIPlayerState* US_RESULT_NEW::updateInput(ACCharacterPlayer& player)
{
	return nullptr;
}

void US_RESULT_NEW::update(ACCharacterPlayer& player)
{
	UE_LOG(LogTemp, Warning, TEXT("Result_new_Operate"));
}

void US_RESULT_NEW::enter(ACCharacterPlayer& player)
{
}

void US_RESULT_NEW::exit(ACCharacterPlayer& player)
{
}

void US_RESULT_NEW::Destroy()
{
}
