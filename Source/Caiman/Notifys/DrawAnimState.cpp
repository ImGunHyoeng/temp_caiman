// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifys/DrawAnimState.h"
#include "CCharacterPlayer.h"
#include "FSM/ACTOR_STATE/DRAWING_A.h"

void UDrawAnimState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);
	if (MeshComp)
	{
		ACCharacterPlayer* Player = Cast<ACCharacterPlayer>(MeshComp->GetOwner());
		if (Player)
		{
			ADRAWING_A* DRAW = Cast<ADRAWING_A>(Player->GetCurPlayerState()->GetSubState().GetObject());

			if (DRAW)
				DRAW->canChange = true;

		}
	}
}

void UDrawAnimState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);
	if (MeshComp)
	{
		ACCharacterPlayer* Player = Cast<ACCharacterPlayer>(MeshComp->GetOwner());
		if (Player)
		{
			ADRAWING_A* DRAW = Cast<ADRAWING_A>(Player->GetCurPlayerState()->GetSubState().GetObject());
			if (DRAW)
				DRAW->end = true;
		}
	}
}
