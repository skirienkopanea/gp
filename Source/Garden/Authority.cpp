// Fill out your copyright notice in the Description page of Project Settings.


#include "Authority.h"

AAuthority::AAuthority() {
	SetMobility(EComponentMobility::Movable);
	PrimaryActorTick.bCanEverTick = true;
}

void AAuthority::BeginPlay() {
	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
}

void AAuthority::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (HasAuthority()) {
		SetActorLocation(GetActorLocation());
	}
}


