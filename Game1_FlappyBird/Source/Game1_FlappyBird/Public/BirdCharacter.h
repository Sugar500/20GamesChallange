// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "BirdCharacter.generated.h"

class UInputMappingContext;
struct FInputActionValue;
class UInputAction;

UCLASS()
class GAME1_FLAPPYBIRD_API ABirdCharacter : public APaperCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABirdCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called to launch the character in the z-axis by LaunchSpeed
	void Launch(const FInputActionValue& Value);

	UPROPERTY(EditDefaultsOnly, Category="Enhanced Input")
	TObjectPtr<UInputMappingContext> MainInputMapping;
	UPROPERTY(EditDefaultsOnly, Category="Enhanced Input")
	TObjectPtr<UInputAction> IA_JumpAction;

	// The speed to launch the character
	UPROPERTY(EditDefaultsOnly)
	float LaunchSpeed = 5.f;
private:
	TObjectPtr<UCapsuleComponent> CapsuleComponent = nullptr;
};
