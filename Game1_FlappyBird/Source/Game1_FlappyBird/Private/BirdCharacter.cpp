// Fill out your copyright notice in the Description page of Project Settings.


#include "BirdCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "LandscapeComponent.h"
#include "LaunchComponent.h"
#include "ResetComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABirdCharacter::ABirdCharacter()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// In this program this is unneeded
	PrimaryActorTick.bCanEverTick = false;

	GetCapsuleComponent()->SetSimulatePhysics(true);

	LaunchComponent = CreateDefaultSubobject<ULaunchComponent>(TEXT("MovementComponent"));
}

// Called when the game starts or when spawned
void ABirdCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Set Main Input Mapping
	// Input mapping for enhanced input is found in the enhanced local player subsystem.
	// Not setting input mapping would make it not work at all
	const APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if(!PlayerController) return;
	const ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();
	if(!LocalPlayer) return;
	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
	if(!Subsystem) return;

	// Main Input Mapping is Primary (only in this game) Input
	Subsystem->AddMappingContext(MainInputMapping, 0);

	UCapsuleComponent* Collider = AActor::FindComponentByClass<UCapsuleComponent>();
	Collider->OnComponentBeginOverlap.AddDynamic(this, &ABirdCharacter::OnBeginOverlap);
}

// Called to bind functionality to input
void ABirdCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// The enhanced input component allows one to bind Input Actions to Events and functions
	UEnhancedInputComponent* Component = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if(!Component) return;

	// Binding the function for jumping/launching on the jump action triggered
	// This allows for the player to speed up as they continue to hold a bound key
	Component->BindAction(IA_JumpAction, ETriggerEvent::Triggered, this, &ThisClass::Launch);
}

void ABirdCharacter::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// If the other actor has a reset component
	if(const UResetComponent* ResetComponent = OtherActor->GetComponentByClass<UResetComponent>();
		ResetComponent != nullptr)
	{
		// Reset the level
		const FName LevelName = GetWorld()->GetAuthGameMode()->GetLevel()->GetFName();
		UGameplayStatics::OpenLevel(GetWorld(), LevelName, false);
	}

	
}


// Called every frame
void ABirdCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABirdCharacter::Launch(const FInputActionValue& Value)
{
	LaunchComponent->Launch();
}
