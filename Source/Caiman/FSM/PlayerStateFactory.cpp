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
	TScriptInterface<IIPlayerState> temp = NewObject<AS_IDLE_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot(true);
	return temp;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateD_IDLE()
{
	TScriptInterface<IIPlayerState> temp = NewObject<AD_IDLE_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot(true);
	return temp;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateS_WALK()
{
	TScriptInterface<IIPlayerState> temp = NewObject<AS_WALK_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot(true);
	return temp;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateS_RUN()
{
	TScriptInterface<IIPlayerState> temp = NewObject<AS_RUN_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot(true);
	return temp;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateS_ROLL()
{
	TScriptInterface<IIPlayerState> temp = NewObject<AS_ROLL_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot(true);
	return temp;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateSHEATHING()
{
	TScriptInterface<IIPlayerState> temp = NewObject<ASHEATHING_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot(true);
	return temp;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreatePARRINGSUCCESS()
{
	TScriptInterface<IIPlayerState> temp = NewObject<APARRINGSUCCESS_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot(true);
	return temp;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreatePARRING()
{
	TScriptInterface<IIPlayerState> temp = NewObject<APARRING_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot(true);
	return temp;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateJUMPATTACK()
{
	TScriptInterface<IIPlayerState> temp = NewObject<AJUMPATTACK_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot(true);
	return temp;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateJUMP()
{
	TScriptInterface<IIPlayerState> temp = NewObject<AJUMP_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot(true);
	return temp;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateGROUNDED()
{
	TScriptInterface<IIPlayerState> temp = NewObject<AGROUNDED_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot(true);
	return temp;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateDRAWING()
{
	TScriptInterface<IIPlayerState> temp = NewObject<ADRAWING_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot(true);
	return temp;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateDEFENSELESS()
{
	TScriptInterface<IIPlayerState> temp = NewObject<ADEFENSELESS_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot(true);
	return temp;
}



TScriptInterface<IIPlayerState> PlayerStateFactory::CreateD_WALK()
{
	TScriptInterface<IIPlayerState> temp = NewObject<AD_WALK_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot(true);
	return temp;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateCHARGINGATTACK()
{
	TScriptInterface<IIPlayerState> temp = NewObject<ACHARGINGATTACK_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot(true);
	return temp;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateATTACK()
{
	TScriptInterface<IIPlayerState> temp = NewObject<AATTACK_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot(true);
	return temp;
}