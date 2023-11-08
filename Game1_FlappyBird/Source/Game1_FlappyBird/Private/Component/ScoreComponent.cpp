// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/ScoreComponent.h"

#include "Component/ResetComponent.h"


// Sets default values for this component's properties
UScoreComponent::UScoreComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UScoreComponent::BeginPlay()
{
	Super::BeginPlay();

	UPrimitiveComponent* ColliderComponent = GetOwner()->GetComponentByClass<UPrimitiveComponent>();
	ColliderComponent->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginOverlap);
}


// Called every frame
void UScoreComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UScoreComponent::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(const UResetComponent* ResetComponent = OtherActor->GetComponentByClass<UResetComponent>();
		ResetComponent == nullptr) return;
	
	ChangeScoreDelegate.Broadcast(ScoreValue);
	
}

