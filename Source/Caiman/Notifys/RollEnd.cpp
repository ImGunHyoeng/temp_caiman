// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifys/RollEnd.h"
#include "CCharacterPlayer.h"
#include "FSM/ACTOR_STATE/AFSMCollection.h"

void URollEnd::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (MeshComp)
	{
		ACCharacterPlayer* Player = Cast<ACCharacterPlayer>(MeshComp->GetOwner());
		if (Player)
		{
			if (AS_ROLL_A* temp = Cast<AS_ROLL_A>(Player->getCurState()->GetSubState().GetObject()))
			{
				temp->isRoll = false;
				Player->SetWaitFrame(2);
			}
		}
	}
}
