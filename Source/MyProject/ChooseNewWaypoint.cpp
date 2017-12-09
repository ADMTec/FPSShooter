// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNewWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNewWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {

	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	UE_LOG(LogTemp, Warning, TEXT("Waypoint index: %i"), index);
	return EBTNodeResult::Succeeded;
}

