// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class IIPlayerState;
class CAIMAN_API PlayerStateFactory
{
	UPROPERTY()
	class ACCharacterPlayer* context;

	//팩토리에서 변수생성해서 사용
	TScriptInterface<IIPlayerState> attack;
	TScriptInterface<IIPlayerState> chargeAttack;
	TScriptInterface<IIPlayerState> d_Idle;
	TScriptInterface<IIPlayerState> d_Walk;
	TScriptInterface<IIPlayerState> defenseless;
	TScriptInterface<IIPlayerState> drawing;
	TScriptInterface<IIPlayerState> grounded;
	TScriptInterface<IIPlayerState> hit;
	TScriptInterface<IIPlayerState> invincibility;
	TScriptInterface<IIPlayerState> jump;
	TScriptInterface<IIPlayerState> jumpattack;
	TScriptInterface<IIPlayerState> normal;
	TScriptInterface<IIPlayerState> parring;
	TScriptInterface<IIPlayerState> parringsuccess;
	TScriptInterface<IIPlayerState> s_idle;
	TScriptInterface<IIPlayerState> s_roll;
	TScriptInterface<IIPlayerState> s_run;
	TScriptInterface<IIPlayerState> s_walk;
	TScriptInterface<IIPlayerState> sheathing;
	TScriptInterface<IIPlayerState> superarmor;
	TScriptInterface<IIPlayerState> s_rest;
	TScriptInterface<IIPlayerState> d_rest;
	TScriptInterface<IIPlayerState> knockback;
	TScriptInterface<IIPlayerState> superchargeattack;


	
public:
	PlayerStateFactory(class ACCharacterPlayer* input);
	TScriptInterface<IIPlayerState>CreateS_IDLE();
	TScriptInterface<IIPlayerState>CreateS_WALK();
	TScriptInterface<IIPlayerState>CreateS_RUN();
	TScriptInterface<IIPlayerState>CreateS_ROLL();
	TScriptInterface<IIPlayerState>CreateSHEATHING();
	TScriptInterface<IIPlayerState>CreatePARRINGSUCCESS();
	TScriptInterface<IIPlayerState>CreatePARRING();
	TScriptInterface<IIPlayerState>CreateJUMPATTACK();
	TScriptInterface<IIPlayerState>CreateJUMP();
	TScriptInterface<IIPlayerState>CreateGROUNDED();
	TScriptInterface<IIPlayerState>CreateDRAWING();
	TScriptInterface<IIPlayerState>CreateDEFENSELESS();
	TScriptInterface<IIPlayerState>CreateD_WALK();
	TScriptInterface<IIPlayerState>CreateD_IDLE();
	TScriptInterface<IIPlayerState>CreateCHARGINGATTACK();
	TScriptInterface<IIPlayerState>CreateATTACK();
	TScriptInterface<IIPlayerState>CreateHIT();
	TScriptInterface<IIPlayerState>CreateNORMAL();
	TScriptInterface<IIPlayerState>CreateINVINCIBILITY();
	TScriptInterface<IIPlayerState>CreateSUPERARMOR();
	TScriptInterface<IIPlayerState>CreateD_Rest();
	TScriptInterface<IIPlayerState>CreateS_Rest();
	TScriptInterface<IIPlayerState>CreateKNOCKBACK();
	TScriptInterface<IIPlayerState>CreateSUPERCHARGINGATTACK();
	~PlayerStateFactory();
};
