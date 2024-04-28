// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifys/ParringEnd.h"
#include "CCharacterPlayer.h"
#include "FSM/ACTOR_STATE/PARRING_A.h"

void UParringEnd::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	if (MeshComp)
	{
		ACCharacterPlayer* Player = Cast<ACCharacterPlayer>(MeshComp->GetOwner());
		if (Player)
		{
			if (APARRING_A* temp = Cast<APARRING_A>(Player->getCurState()->GetSubState().GetObject()))
			{
				Player->SetParringEnd(true);
				//Player->SetWaitFrame(2);
			}
		}
	}
}
