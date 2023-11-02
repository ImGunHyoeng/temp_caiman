// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_ComboAttack.h"
#include "CCharacterPlayer.h"
void UAnimNotify_ComboAttack::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	if (MeshComp)
	{
		ACCharacterPlayer* Player = Cast<ACCharacterPlayer>(MeshComp->GetOwner());
		if (Player)
		{
			Player->AttackCheck();
		}
	}
}

