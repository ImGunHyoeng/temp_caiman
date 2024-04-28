// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CCharacterPlayer.h"
#include "PlayerStateFactory.generated.h"

/**
 * 
 */
class IIPlayerState;
UCLASS()
class CAIMAN_API UPlayerStateFactory : public UObject
{
	GENERATED_BODY()


	//팩토리에서 변수생성해서 사용
	IIPlayerState* attack;
	IIPlayerState* chargeAttack;
	IIPlayerState* d_Idle;
	IIPlayerState* d_Walk;
	IIPlayerState* defenseless;
	IIPlayerState* drawing;
	IIPlayerState* grounded;
	IIPlayerState* hit;
	IIPlayerState* invincibility;
	IIPlayerState* jump;
	IIPlayerState* jumpattack;
	IIPlayerState* normal;
	IIPlayerState* parring;
	IIPlayerState* parringsuccess;
	IIPlayerState* s_idle;
	IIPlayerState* s_roll;
	IIPlayerState* s_run;
	IIPlayerState* s_walk;
	IIPlayerState* sheathing;
	IIPlayerState* superarmor;
	IIPlayerState* s_rest;
	IIPlayerState* d_rest;
	IIPlayerState* knockback;
	IIPlayerState* superchargeattack;



public:
	UPROPERTY()
	ACCharacterPlayer* context;
	void Set(ACCharacterPlayer* input);
	UPlayerStateFactory() {};
	IIPlayerState*CreateS_IDLE();
	IIPlayerState*CreateS_WALK();
	IIPlayerState*CreateS_RUN();
	IIPlayerState*CreateS_ROLL();
	IIPlayerState*CreateSHEATHING();
	IIPlayerState*CreatePARRINGSUCCESS();
	IIPlayerState*CreatePARRING();
	IIPlayerState*CreateJUMPATTACK();
	IIPlayerState*CreateJUMP();
	IIPlayerState*CreateGROUNDED();
	IIPlayerState*CreateDRAWING();
	IIPlayerState*CreateDEFENSELESS();
	IIPlayerState*CreateD_WALK();
	IIPlayerState*CreateD_IDLE();
	IIPlayerState*CreateCHARGINGATTACK();
	IIPlayerState*CreateATTACK();
	IIPlayerState*CreateHIT();
	IIPlayerState*CreateNORMAL();
	IIPlayerState*CreateINVINCIBILITY();
	IIPlayerState*CreateSUPERARMOR();
	IIPlayerState*CreateD_Rest();
	IIPlayerState*CreateS_Rest();
	IIPlayerState*CreateKNOCKBACK();
	IIPlayerState*CreateSUPERCHARGINGATTACK();
	~UPlayerStateFactory();
};
