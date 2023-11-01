// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TeleportActor.generated.h"

class UBoxComponent;

UCLASS()
class GAME1_FLAPPYBIRD_API ATeleportActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATeleportActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditInstanceOnly)
	TObjectPtr<AActor> TeleportLocation;
	
private:
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxCollider;
};
