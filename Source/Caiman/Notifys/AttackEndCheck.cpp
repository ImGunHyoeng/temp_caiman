// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifys/AttackEndCheck.h"
#include "CCharacterPlayer.h"
//#include "FSM/OBJECT_STATE/ATTACK_O.h"
#include "FSM/ACTOR_STATE/AFSMCollection.h"
#include "FSM\IPlayerState.h"
void UAttackEndCheck::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	if (MeshComp)
	{
		ACCharacterPlayer* Player = Cast<ACCharacterPlayer>(MeshComp->GetOwner());
		if (Player)
		{

			AATTACK_A* AT = Cast<AATTACK_A>(Player->GetCurPlayerState().GetObject());
			if(AT)
				AT->AttackStateEnd();
		}
	}
}
