// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/LaunchComponent.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"

// Sets default values for this component's properties
ULaunchComponent::ULaunchComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void ULaunchComponent::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ULaunchComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void ULaunchComponent::Launch()
{
	// Adding a force vector in the z-axis allows the character to be launch upwards
	// Because the z-axis is up in 3D and I didn't feel like putting the extra effort into changing it
	const ACharacter* Character = Cast<ACharacter>(GetOwner());
	Character->GetCapsuleComponent()->AddImpulse(FVector(0.f, 0.f, LaunchSpeed));
}
