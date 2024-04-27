// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifys/SuperEnd.h"
#include "CCharacterPlayer.h"
#include "FSM/ACTOR_STATE/SUPERARMOR_A.h"
void USuperEnd::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	if (MeshComp)
	{
		ACCharacterPlayer* Player = Cast<ACCharacterPlayer>(MeshComp->GetOwner());
		if (Player)
		{
			if (ASUPERARMOR_A* temp = Cast<ASUPERARMOR_A>(Player->getCurState().GetObject()))
			{
				temp->end = true;
			}
		}
	}
}
