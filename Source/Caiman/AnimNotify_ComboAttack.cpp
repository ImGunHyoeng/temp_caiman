// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_ComboAttack.h"
#include "CCharacterPlayer.h"
#include "FSM\IPlayerState.h"
#include "FSM/ACTOR_STATE/ATTACK_A.h"
void UAnimNotify_ComboAttack::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	if (MeshComp)
	{
		ACCharacterPlayer* Player = Cast<ACCharacterPlayer>(MeshComp->GetOwner());
		if (Player)
		{
			//Player->AttackCheck();
			
			if (AATTACK_A* currentState = Cast<AATTACK_A>(Player->GetCurPlayerState()->GetSubState()))
			{
				currentState->AttackStateDone();
			}
			//if (ATTACK* attack = Cast<ATTACK>(Player->GetCurPlayerState()))
			//{
			//	
			//}
		}
	}
}

