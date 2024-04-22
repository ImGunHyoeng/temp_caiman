// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifys/IsLeftMousePressing.h"
#include "CCharacterPlayer.h"
#include "FSM/ACTOR_STATE/AFSMCollection.h"
#include "FSM\IPlayerState.h"
void UIsLeftMousePressing::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	if (!MeshComp)
		return;
	
	ACCharacterPlayer* Player = Cast<ACCharacterPlayer>(MeshComp->GetOwner());
	if (!Player)
		return;
		
	AATTACK_A* AT = Cast<AATTACK_A>(Player->GetCurPlayerState().GetObject());
	if (!AT)
		return;
	if (Player->getPlayerController()->IsInputKeyDown(EKeys::LeftMouseButton))
		AT->ChangeChargeAttack();
			
		
		
	
}
