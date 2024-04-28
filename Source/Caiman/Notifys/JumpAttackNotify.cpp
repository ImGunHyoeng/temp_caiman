// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifys/JumpAttackNotify.h"
#include "CCharacterPlayer.h"
#include "FSM/ACTOR_STATE/JUMPATTACK_A.h"

void UJumpAttackNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	if (MeshComp)
	{
		ACCharacterPlayer* Player = Cast<ACCharacterPlayer>(MeshComp->GetOwner());
		if (Player)
		{
			if (AJUMPATTACK_A* temp = Cast<AJUMPATTACK_A>(Player->getCurState()->GetSubState()))
			{
				temp->end = true;
			}
		}
	}
}
