// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/PlayerStateFactory.h"
#include "FSM/IPlayerState.h"
#include "FSM/ACTOR_STATE/AFSMCollection.h"
#include "CCharacterPlayer.h"
PlayerStateFactory::PlayerStateFactory(ACCharacterPlayer* input)
{
	context = input;
	attack = NULL;
	chargeAttack = NULL;
	d_Idle = NULL;
	d_Walk = NULL;
	defenseless = NULL;
	drawing = NULL;
	grounded = NULL;
	hit = NULL;
	drawing = NULL;
	invincibility = NULL;
	jump = NULL;
	jumpattack = NULL;
	normal = NULL;
	parring = NULL;
	parringsuccess = NULL;
	s_idle = NULL;
	s_roll = NULL;
	s_run = NULL;
	s_walk = NULL;
	sheathing = NULL;
	superarmor = NULL;
	s_rest = NULL;
	d_rest = NULL;

}

PlayerStateFactory::~PlayerStateFactory()
{
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateS_IDLE()
{
	if (s_idle)
		return s_idle;
	TScriptInterface<IIPlayerState> temp = NewObject<AS_IDLE_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	s_idle = temp;
	return s_idle;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateD_IDLE()
{
	if (d_Idle)
		return d_Idle;
	TScriptInterface<IIPlayerState> temp = NewObject<AD_IDLE_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	d_Idle = temp;
	return d_Idle;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateS_WALK()
{
	if (s_walk)
		return s_walk;
	TScriptInterface<IIPlayerState> temp = NewObject<AS_WALK_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	s_walk = temp;
	return s_walk;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateS_RUN()
{
	if (s_run)
		return s_run;
	TScriptInterface<IIPlayerState> temp = NewObject<AS_RUN_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	s_run = temp;
	return s_run;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateS_ROLL()
{
	if (s_roll)
		return s_roll;
	TScriptInterface<IIPlayerState> temp = NewObject<AS_ROLL_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	s_roll = temp;
	return s_roll;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateSHEATHING()
{
	if (sheathing)
		return sheathing;
	TScriptInterface<IIPlayerState> temp = NewObject<ASHEATHING_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	sheathing = temp;
	return sheathing;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreatePARRINGSUCCESS()
{
	if (parringsuccess)
		return parringsuccess;
	TScriptInterface<IIPlayerState> temp = NewObject<APARRINGSUCCESS_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	parringsuccess = temp;
	return parringsuccess;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreatePARRING()
{
	if (parring)
		return parring;
	TScriptInterface<IIPlayerState> temp = NewObject<APARRING_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	parring = temp;
	return parring;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateJUMPATTACK()
{
	if (jumpattack)
		return jumpattack;
	TScriptInterface<IIPlayerState> temp = NewObject<AJUMPATTACK_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	jumpattack = temp;
	return jumpattack;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateJUMP()
{
	if (jump)
		return jump;
	TScriptInterface<IIPlayerState> temp = NewObject<AJUMP_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	jump = temp;
	return jump;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateGROUNDED()
{
	if (grounded)
		return grounded;
	TScriptInterface<IIPlayerState> temp = NewObject<AGROUNDED_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	grounded = temp;
	return grounded;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateDRAWING()
{
	if (drawing)
		return drawing;
	TScriptInterface<IIPlayerState> temp = NewObject<ADRAWING_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	drawing = temp;
	return drawing;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateDEFENSELESS()
{
	if (defenseless)
		return defenseless;
	TScriptInterface<IIPlayerState> temp = NewObject<ADEFENSELESS_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	defenseless = temp;
	return defenseless;
}



TScriptInterface<IIPlayerState> PlayerStateFactory::CreateD_WALK()
{
	if (d_Walk)
		return d_Walk;
	TScriptInterface<IIPlayerState> temp = NewObject<AD_WALK_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	d_Walk = temp;
	return d_Walk;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateCHARGINGATTACK()
{
	if (chargeAttack)
		return chargeAttack;
	TScriptInterface<IIPlayerState> temp = NewObject<ACHARGINGATTACK_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	chargeAttack = temp;
	return chargeAttack;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateATTACK()
{
	if (attack)
		return attack;
	TScriptInterface<IIPlayerState> temp = NewObject<AATTACK_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	attack = temp;
	return attack;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateHIT()
{
	if (hit)
		return hit;
	TScriptInterface<IIPlayerState> temp = NewObject<AHIT_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot(true);
	hit = temp;
	return hit;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateNORMAL()
{
	if (normal)
		return normal;
	TScriptInterface<IIPlayerState> temp = NewObject<ANORMAL_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot(true);
	normal = temp;
	return normal;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateINVINCIBILITY()
{
	if (invincibility)
		return invincibility;
	TScriptInterface<IIPlayerState> temp = NewObject<AINVINCIBILITY_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot(true);
	invincibility = temp;
	return invincibility;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateSUPERARMOR()
{
	if (superarmor)
		return superarmor;
	TScriptInterface<IIPlayerState> temp = NewObject<ASUPERARMOR_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot(true);
	superarmor = temp;
	return superarmor;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateD_Rest()
{
	if (d_rest)
		return d_rest;
	TScriptInterface<IIPlayerState> temp = NewObject<AD_REST_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	d_rest = temp;
	return d_rest;
}

TScriptInterface<IIPlayerState> PlayerStateFactory::CreateS_Rest()
{
	if (s_rest)
		return s_rest;
	TScriptInterface<IIPlayerState> temp = NewObject<AS_REST_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	s_rest = temp;
	return s_rest;
}
