// Fill out your copyright notice in the Description page of Project Settings.
#include "FSM/PlayerStateFactory.h"
#include "FSM/IPlayerState.h"
#include "FSM/ACTOR_STATE/AFSMCollection.h"
#include "CCharacterPlayer.h"
void UPlayerStateFactory::Set(ACCharacterPlayer* input)
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
	knockback = NULL;
	superchargeattack = NULL;

}

UPlayerStateFactory::~UPlayerStateFactory()
{
	if (attack)
		attack->Destroy();
	if (chargeAttack)
		chargeAttack->Destroy();
	if (d_Idle)
		d_Idle->Destroy();
	if (d_Walk)
		d_Walk->Destroy();
	if (defenseless)
		defenseless->Destroy();
	if (drawing)
		drawing->Destroy();
	if (grounded)
		grounded->Destroy();
	if (hit)
		hit->Destroy();
	if (drawing)
		drawing->Destroy();
	if (invincibility)
		invincibility->Destroy();
	if (jump)
		jump->Destroy();
	if (jumpattack)
		jumpattack->Destroy();
	if (normal)
		normal->Destroy();
	if (parring)
		parring->Destroy();
	if (parringsuccess)
		parringsuccess->Destroy();
	if (s_idle)
		s_idle->Destroy();
	if (s_roll)
		s_roll->Destroy();
	if (s_run)
		s_run->Destroy();
	if (s_walk)
		s_walk->Destroy();
	if (sheathing)
		sheathing->Destroy();
	if (superarmor)
		superarmor->Destroy();
	if (s_rest)
		s_rest->Destroy();
	if (d_rest)
		d_rest->Destroy();
	if (knockback)
		knockback->Destroy();
	if (superchargeattack)
		superchargeattack->Destroy();

}

TScriptInterface<IIPlayerState> UPlayerStateFactory::CreateS_IDLE()
{
	if (s_idle)
		return s_idle;
	s_idle = NewObject<AS_IDLE_A>();
	s_idle->SetInitalProperty(context, this);
	s_idle->SetRoot();
	return s_idle;
}

TScriptInterface<IIPlayerState> UPlayerStateFactory::CreateD_IDLE()
{
	if (d_Idle)
		return d_Idle;
	d_Idle = NewObject<AD_IDLE_A>();
	d_Idle->SetInitalProperty(context, this);
	d_Idle->SetRoot();
	return d_Idle;
}

TScriptInterface<IIPlayerState> UPlayerStateFactory::CreateS_WALK()
{
	if (s_walk)
		return s_walk;
	s_walk = NewObject<AS_WALK_A>();
	s_walk->SetInitalProperty(context, this);
	s_walk->SetRoot();
	return s_walk;
}

TScriptInterface<IIPlayerState> UPlayerStateFactory::CreateS_RUN()
{
	if (s_run)
		return s_run;
	s_run = NewObject<AS_RUN_A>();
	s_run->SetInitalProperty(context, this);
	s_run->SetRoot();
	return s_run;
}

TScriptInterface<IIPlayerState> UPlayerStateFactory::CreateS_ROLL()
{
	if (s_roll)
		return s_roll;
	s_roll = NewObject<AS_ROLL_A>();
	s_roll->SetInitalProperty(context, this);
	s_roll->SetRoot();
	return s_roll;
}

TScriptInterface<IIPlayerState> UPlayerStateFactory::CreateSHEATHING()
{
	if (sheathing)
		return sheathing;
	sheathing = NewObject<ASHEATHING_A>();
	sheathing->SetInitalProperty(context, this);
	sheathing->SetRoot();
	return sheathing;
}

TScriptInterface<IIPlayerState> UPlayerStateFactory::CreatePARRINGSUCCESS()
{
	if (parringsuccess)
		return parringsuccess;
	parringsuccess = NewObject<APARRINGSUCCESS_A>();
	parringsuccess->SetInitalProperty(context, this);
	parringsuccess->SetRoot();
	parringsuccess = parringsuccess;
	return parringsuccess;
}

TScriptInterface<IIPlayerState> UPlayerStateFactory::CreatePARRING()
{
	if (parring)
		return parring;
	TScriptInterface<IIPlayerState> temp = NewObject<APARRING_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	parring = temp;
	return parring;
}

TScriptInterface<IIPlayerState> UPlayerStateFactory::CreateJUMPATTACK()
{
	if (jumpattack)
		return jumpattack;
	TScriptInterface<IIPlayerState> temp = NewObject<AJUMPATTACK_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	jumpattack = temp;
	return jumpattack;
}

TScriptInterface<IIPlayerState> UPlayerStateFactory::CreateJUMP()
{
	if (jump)
		return jump;
	TScriptInterface<IIPlayerState> temp = NewObject<AJUMP_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	jump = temp;
	return jump;
}

TScriptInterface<IIPlayerState> UPlayerStateFactory::CreateGROUNDED()
{
	if (grounded)
		return grounded;
	TScriptInterface<IIPlayerState> temp = NewObject<AGROUNDED_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	grounded = temp;
	return grounded;
}

TScriptInterface<IIPlayerState> UPlayerStateFactory::CreateDRAWING()
{
	if (drawing)
		return drawing;
	TScriptInterface<IIPlayerState> temp = NewObject<ADRAWING_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	drawing = temp;
	return drawing;
}

TScriptInterface<IIPlayerState> UPlayerStateFactory::CreateDEFENSELESS()
{
	if (defenseless)
		return defenseless;
	TScriptInterface<IIPlayerState> temp = NewObject<ADEFENSELESS_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	defenseless = temp;
	return defenseless;
}



TScriptInterface<IIPlayerState> UPlayerStateFactory::CreateD_WALK()
{
	if (d_Walk)
		return d_Walk;
	TScriptInterface<IIPlayerState> temp = NewObject<AD_WALK_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	d_Walk = temp;
	return d_Walk;
}

TScriptInterface<IIPlayerState> UPlayerStateFactory::CreateCHARGINGATTACK()
{
	if (chargeAttack)
		return chargeAttack;
	TScriptInterface<IIPlayerState> temp = NewObject<ACHARGINGATTACK_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	chargeAttack = temp;
	return chargeAttack;
}

TScriptInterface<IIPlayerState> UPlayerStateFactory::CreateATTACK()
{
	if (attack)
		return attack;
	TScriptInterface<IIPlayerState> temp = NewObject<AATTACK_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	attack = temp;
	return attack;
}

TScriptInterface<IIPlayerState> UPlayerStateFactory::CreateHIT()
{
	if (hit)
		return hit;
	TScriptInterface<IIPlayerState> temp = NewObject<AHIT_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot(true);
	hit = temp;
	return hit;
}

TScriptInterface<IIPlayerState> UPlayerStateFactory::CreateNORMAL()
{
	if (normal)
		return normal;
	TScriptInterface<IIPlayerState> temp = NewObject<ANORMAL_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot(true);
	normal = temp;
	return normal;
}

TScriptInterface<IIPlayerState> UPlayerStateFactory::CreateINVINCIBILITY()
{
	if (invincibility)
		return invincibility;
	TScriptInterface<IIPlayerState> temp = NewObject<AINVINCIBILITY_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot(true);
	invincibility = temp;
	return invincibility;
}

TScriptInterface<IIPlayerState> UPlayerStateFactory::CreateSUPERARMOR()
{
	if (superarmor)
		return superarmor;
	TScriptInterface<IIPlayerState> temp = NewObject<ASUPERARMOR_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot(true);
	superarmor = temp;
	return superarmor;
}

TScriptInterface<IIPlayerState> UPlayerStateFactory::CreateD_Rest()
{
	if (d_rest)
		return d_rest;
	TScriptInterface<IIPlayerState> temp = NewObject<AD_REST_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	d_rest = temp;
	return d_rest;
}

TScriptInterface<IIPlayerState> UPlayerStateFactory::CreateS_Rest()
{
	if (s_rest)
		return s_rest;
	TScriptInterface<IIPlayerState> temp = NewObject<AS_REST_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	s_rest = temp;
	return s_rest;
}

TScriptInterface<IIPlayerState> UPlayerStateFactory::CreateKNOCKBACK()
{
	if (knockback)
		return knockback;
	TScriptInterface<IIPlayerState> temp = NewObject<AKNOCKBACK_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	knockback = temp;
	return knockback;
}

TScriptInterface<IIPlayerState> UPlayerStateFactory::CreateSUPERCHARGINGATTACK()
{
	if (superchargeattack)
		return superchargeattack;
	TScriptInterface<IIPlayerState> temp = NewObject<ASUPERCHARGINGATTACK_A>();
	temp->SetInitalProperty(context, this);
	temp->SetRoot();
	superchargeattack = temp;
	return superchargeattack;
}
