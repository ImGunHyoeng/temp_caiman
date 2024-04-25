// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class IIPlayerState;
class CAIMAN_API PlayerStateFactory
{
	class ACCharacterPlayer* context;
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
	~PlayerStateFactory();
};
