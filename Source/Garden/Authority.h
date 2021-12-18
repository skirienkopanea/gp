// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Authority.generated.h"

/**
 * 
 */
UCLASS()
class GARDEN_API AAuthority : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AAuthority();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
};
