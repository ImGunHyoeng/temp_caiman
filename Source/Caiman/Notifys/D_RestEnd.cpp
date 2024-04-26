// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifys/D_RestEnd.h"
#include "CCharacterPlayer.h"
#include "FSM/ACTOR_STATE/AFSMCollection.h"

void UD_RestEnd::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	if (MeshComp)
	{
		ACCharacterPlayer* Player = Cast<ACCharacterPlayer>(MeshComp->GetOwner());
		if (Player)
		{
			if (AD_REST_A* temp = Cast<AD_REST_A>(Player->getCurState()->GetSubState().GetObject()))
			{
				temp->IsEnd= true;
				//Player->SetWaitFrame(2);
			}
		}
	}
}
