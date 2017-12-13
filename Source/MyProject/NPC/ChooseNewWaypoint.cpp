// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNewWaypoint.h"
#include "AIController.h"
#include "PatrolRouteComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNewWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {

	// Get the patrol points
	auto aiController = OwnerComp.GetAIOwner();
	auto controlledPawn = aiController->GetPawn();
	auto patrolComp = controlledPawn->FindComponentByClass<UPatrolRouteComponent>();

	// if there is no control comp, return failed
	if (!ensure(patrolComp)) { return EBTNodeResult::Failed;}
	auto patrolPoints = patrolComp->GetPatrolPoints();

	if (patrolPoints.Num() == 0) { return EBTNodeResult::Failed;}
	// set next waypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, patrolPoints[index]);

	// cycle index
	index++;

	auto newIndex = index % patrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, newIndex);

	return EBTNodeResult::Succeeded;
}



