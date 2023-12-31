// Fill out your copyright notice in the Description page of Project Settings.


#include "CAnimNotifyState_Trace.h"
#include "CCharacterPlayer.h"
#include "CTraceComponent.h"

void UCAnimNotifyState_Trace::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	
	Super::NotifyBegin(MeshComp, Animation,TotalDuration,EventReference);

	if (MeshComp)
	{
		ACCharacterPlayer* Player = Cast<ACCharacterPlayer>(MeshComp->GetOwner());
		if (Player)
		{
			UActorComponent* ActorComp = Player->GetComponentByClass(UCTraceComponent::StaticClass());
			UCTraceComponent* Tracecomp = Cast<UCTraceComponent>(ActorComp);
			Tracecomp->TsetActive();
		}
	}
}



void UCAnimNotifyState_Trace::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);
	if (MeshComp)
	{
		ACCharacterPlayer* Player = Cast<ACCharacterPlayer>(MeshComp->GetOwner());
		if (Player)
		{
			UActorComponent* ActorComp = Player->GetComponentByClass(UCTraceComponent::StaticClass());
			UCTraceComponent* Tracecomp = Cast<UCTraceComponent>(ActorComp);
			Tracecomp->TsetActive(false);
		}
	}

}
