// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class GARDEN_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UMyGameInstance(const FObjectInitializer& ObjectInitializer);
	virtual void Init();

	UFUNCTION(exec)
	void Host();

	UFUNCTION(exec)
	void Join(const FString& Address);
};
