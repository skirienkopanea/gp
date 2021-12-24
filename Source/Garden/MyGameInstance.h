// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuInterface.h"
#include "MyGameInstance.generated.h"


/**
 * 
 */
UCLASS()
class GARDEN_API UMyGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

public:
	UMyGameInstance(const FObjectInitializer& ObjectInitializer);
	virtual void Init();

	UFUNCTION(BlueprintCallable)
	void LoadMenu();

	UFUNCTION(BlueprintCallable)
	void LoadInGameMenu();

	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString& Address);

	virtual void LoadMainMenu() override;
	virtual void QuitGame() override;

private:
	TSubclassOf<class UUserWidget> MenuClass;
	TSubclassOf<class UUserWidget> InGameMenuClass;
	class UMainMenu* Menu;
	class UInGameMenu* InGameMenu;

	UPROPERTY()
	UInputComponent* InputComponent = nullptr;
};
