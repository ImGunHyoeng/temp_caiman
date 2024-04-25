// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifys/ChargeStart.h"
#include "CCharacterPlayer.h"
#include "FSM/ACTOR_STATE/AFSMCollection.h"
void UChargeStart::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (MeshComp)
	{
		ACCharacterPlayer* Player = Cast<ACCharacterPlayer>(MeshComp->GetOwner());
		if (Player)
		{
			if (ACHARGINGATTACK_A* temp = Cast<ACHARGINGATTACK_A>(Player->getCurState()->GetSubState().GetObject()))
			{
				temp->ChangeDoing(Player);
			}
		}
	}
}