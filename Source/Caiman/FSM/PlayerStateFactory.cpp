// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/PlayerStateFactory.h"
#include "FSM/IPlayerState.h"
#include "FSM/ACTOR_STATE/AFSMCollection.h"
#include "CCharacterPlayer.h"
PlayerStateFactory::PlayerStateFactory(ACCharacterPlayer* input)
{
	context = input;
}

PlayerStateFactory::~PlayerStateFactory()
{
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateS_IDLE()
{
	return NewObject<AS_IDLE_A>();
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateD_IDLE()
{
	return NewObject<AD_IDLE_A>();
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateS_WALK()
{
	return NewObject<AS_WALK_A>();
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateS_RUN()
{
	return NewObject<AS_RUN_A>();
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateS_ROLL()
{
	return NewObject<AS_ROLL_A>();
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateSHEATHING()
{
	return NewObject<ASHEATHING_A>();
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreatePARRINGSUCCESS()
{
	return NewObject<APARRINGSUCCESS_A>();
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreatePARRING()
{
	return NewObject<APARRING_A>();
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateJUMPATTACK()
{
	return NewObject<AJUMPATTACK_A>();
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateJUMP()
{
	return NewObject<AJUMP_A>();
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateGROUNDED()
{
	return NewObject<AGROUNDED_A>();
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateDRAWING()
{
	return NewObject<ADRAWING_A>();
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateDEFENSELESS()
{
	return NewObject<ADEFENSELESS_A>();
}



TScriptInterface<IIPlayerState> PlayerStateFactory::CreateD_WALK()
{
	return NewObject<AD_WALK_A>();
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateCHARGINGATTACK()
{
	return NewObject<ACHARGINGATTACK_A>();
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateATTACK() 
{
	return NewObject<AATTACK_A>();
}