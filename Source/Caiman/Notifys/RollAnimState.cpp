// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifys/RollAnimState.h"
#include "CCharacterPlayer.h"
#include "FSM/ACTOR_STATE/S_ROLL_A.h"

void URollAnimState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);
	if (MeshComp)
	{
		ACCharacterPlayer* Player = Cast<ACCharacterPlayer>(MeshComp->GetOwner());
		if (Player)
		{
			AS_ROLL_A* Sheath = Cast<AS_ROLL_A>(Player->GetCurPlayerState()->GetSubState().GetObject());

			if (Sheath)
				Sheath->isRoll = false;

		}
	}
}

void URollAnimState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);
	if (MeshComp)
	{
		ACCharacterPlayer* Player = Cast<ACCharacterPlayer>(MeshComp->GetOwner());
		if (Player)
		{
			AS_ROLL_A* Sheath = Cast<AS_ROLL_A>(Player->GetCurPlayerState()->GetSubState().GetObject());

			if (Sheath)
				Sheath->end = true;
		}
	}
}
