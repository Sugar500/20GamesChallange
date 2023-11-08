// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LaunchComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GAME1_FLAPPYBIRD_API ULaunchComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	ULaunchComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;

	// Called to launch the character in the z-axis by LaunchSpeed
	void Launch();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// The speed to launch the character
	UPROPERTY(EditDefaultsOnly)
	float LaunchSpeed = 50.f;
};
