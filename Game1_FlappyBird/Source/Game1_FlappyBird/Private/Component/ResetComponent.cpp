// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/ResetComponent.h"

#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UResetComponent::UResetComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

// Called every frame
void UResetComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UResetComponent::BroadcastPlayerDeath() const
{
	CallDeathDelegate.Broadcast();
}

// Called when the game starts
void UResetComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UResetComponent::ResetLevel() const
{
	const FName LevelName = GetWorld()->GetAuthGameMode()->GetLevel()->GetFName();
	UGameplayStatics::OpenLevel(GetWorld(), LevelName, false);
}
