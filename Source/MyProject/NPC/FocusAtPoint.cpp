// Fill out your copyright notice in the Description page of Project Settings.

#include "FocusAtPoint.h"
#include "AIController.h"
#include "Player/FirstPersonCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UFocusAtPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	auto aiController = OwnerComp.GetAIOwner();
	auto controlledPawn = aiController->GetPawn();

	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto actorToFocusOn = BlackboardComp->GetValueAsObject(IndexKey.SelectedKeyName);
	auto enemy = Cast<AActor>(actorToFocusOn);
	if (enemy == nullptr) {
		return EBTNodeResult::Failed;
	}

	aiController->SetFocus(enemy, EAIFocusPriority::Gameplay);

	return EBTNodeResult::Succeeded;
}

