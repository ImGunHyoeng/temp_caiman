// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifys/ParringSuccessEnd.h"
#include "CCharacterPlayer.h"
#include "FSM/ACTOR_STATE/PARRINGSUCCESS_A.h"
void UParringSuccessEnd::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	if (MeshComp)
	{
		ACCharacterPlayer* Player = Cast<ACCharacterPlayer>(MeshComp->GetOwner());
		if (Player)
		{
			if (APARRINGSUCCESS_A* temp = Cast<APARRINGSUCCESS_A>(Player->getCurState()->GetSubState().GetObject()))
			{
				temp->end = true;
			}
		}
	}
}
