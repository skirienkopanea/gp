// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveBox.h"

AMoveBox::AMoveBox()
{
	SetMobility(EComponentMobility::Movable);
	PrimaryActorTick.bCanEverTick = true;
};

void AMoveBox::BeginPlay() {
	Super::BeginPlay();
	if (HasAuthority()) {
		SetReplicates(true);
		SetReplicateMovement(true);
		
	}
}

void AMoveBox::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	if (HasAuthority())
	{
		
		FVector Location = GetActorLocation();


		if ((int)Location.X >= 400) {
			Location = FVector(-200, Location.Y, Location.Z);
			
		}
			Location += FVector(30 * DeltaTime, 0, 0);
	

		SetActorLocation(Location);
	}
}

