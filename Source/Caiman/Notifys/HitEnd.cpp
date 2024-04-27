// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifys/HitEnd.h"
#include "CCharacterPlayer.h"
#include "FSM/ACTOR_STATE/KNOCKBACK_A.h"
void UHitEnd::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	if (MeshComp)
	{
		ACCharacterPlayer* Player = Cast<ACCharacterPlayer>(MeshComp->GetOwner());
		if (Player)
		{
			if (AKNOCKBACK_A* temp = Cast<AKNOCKBACK_A>(Player->getCurState()->GetSubState().GetObject()))
			{
				temp->end = true;
			}
		}
	}
}
