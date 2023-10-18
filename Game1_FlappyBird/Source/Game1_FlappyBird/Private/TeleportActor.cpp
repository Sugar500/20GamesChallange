// Fill out your copyright notice in the Description page of Project Settings.


#include "TeleportActor.h"

#include "Components/BoxComponent.h"


// Sets default values
ATeleportActor::ATeleportActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("CapsuleCollider"));
	SetRootComponent(BoxCollider);
}

// Called when the game starts or when spawned
void ATeleportActor::BeginPlay()
{
	Super::BeginPlay();

	BoxCollider->OnComponentHit.AddDynamic(this, &ATeleportActor::OnHit);
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &ATeleportActor::OnOverlap);
}

// Called every frame
void ATeleportActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATeleportActor::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("Actor Hit!"));
	//OtherActor->SetActorLocation(TeleportLocation->GetActorLocation());
}

void ATeleportActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Actor Overlap!"));
	OtherActor->SetActorLocation(TeleportLocation->GetActorLocation());
}