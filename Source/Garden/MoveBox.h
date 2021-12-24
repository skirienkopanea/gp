// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MoveBox.generated.h"

/**
 * 
 */
UCLASS()
class GARDEN_API AMoveBox : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AMoveBox();
	// Called every frame
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
