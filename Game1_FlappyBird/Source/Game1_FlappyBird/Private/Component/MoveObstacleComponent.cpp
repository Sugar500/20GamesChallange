// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/MoveObstacleComponent.h"


// Sets default values for this component's properties
UMoveObstacleComponent::UMoveObstacleComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UMoveObstacleComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UMoveObstacleComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* owner = GetOwner();
	if(!owner) return;

	owner->AddActorWorldOffset(FVector(MoveSpeed * DeltaTime, 0.f, 0.f));
}

