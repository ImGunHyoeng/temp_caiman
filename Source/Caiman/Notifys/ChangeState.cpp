// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifys/ChangeState.h"
#include "CCharacterPlayer.h"
#include "FSM/ACTOR_STATE/AFSMCollection.h"

void UChangeState::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (MeshComp)
	{
		ACCharacterPlayer* Player = Cast<ACCharacterPlayer>(MeshComp->GetOwner());
		if (Player)
		{
			if (ACHARGINGATTACK_A* temp = Cast<ACHARGINGATTACK_A>(Player->getCurState()->GetSubState().GetObject()))
			{
				temp->changeState = true;
			}
		}
	}
}
