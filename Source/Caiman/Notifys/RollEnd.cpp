// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifys/RollEnd.h"
#include "CCharacterPlayer.h"
#include "FSM/ACTOR_STATE/S_ROLL_A.h"

void URollEnd::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
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
