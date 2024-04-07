// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifys/AttackEndCheck.h"
#include "CCharacterPlayer.h"
#include "FSM\ATTACK.h"
#include "FSM\IPlayerState.h"
void UAttackEndCheck::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	if (MeshComp)
	{
		ACCharacterPlayer* Player = Cast<ACCharacterPlayer>(MeshComp->GetOwner());
		if (Player)
		{

			ATTACK* attack = StaticCast<ATTACK*>(Player->GetCurPlayerState());
			attack->AttackStateEnd();
		}
	}
}
