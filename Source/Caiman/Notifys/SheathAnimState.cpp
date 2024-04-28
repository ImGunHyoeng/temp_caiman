// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifys/SheathAnimState.h"
#include "CCharacterPlayer.h"
#include "FSM/ACTOR_STATE/SHEATHING_A.h"

void USheathAnimState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);
	if (MeshComp)
	{
		ACCharacterPlayer* Player = Cast<ACCharacterPlayer>(MeshComp->GetOwner());
		if (Player)
		{
			ASHEATHING_A* Sheath = Cast<ASHEATHING_A>(Player->GetCurPlayerState()->GetSubState());

			if (Sheath)
				Sheath->canChange = true;

		}
	}
}

void USheathAnimState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);
	if (MeshComp)
	{
		ACCharacterPlayer* Player = Cast<ACCharacterPlayer>(MeshComp->GetOwner());
		if (Player)
		{
			ASHEATHING_A* Sheath = Cast<ASHEATHING_A>(Player->GetCurPlayerState()->GetSubState());
			if (Sheath)
				Sheath->end = true;

		}
	}
}
