// Fill out your copyright notice in the Description page of Project Settings.


#include "..\Public\ColliderActor.h"

#include "Components/BoxComponent.h"


// Sets default values
AColliderActor::AColliderActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("CapsuleCollider"));
	SetRootComponent(BoxCollider);
}

// Called when the game starts or when spawned
void AColliderActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AColliderActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
