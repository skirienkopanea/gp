// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "InGameMenu.generated.h"


/**
 * 
 */
UCLASS()
class GARDEN_API UInGameMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetMenuInterface(IMenuInterface* MI);
	void Setup();
	UFUNCTION()
	void Teardown();

protected:
	virtual bool Initialize() override;
private:

	//The names of these variables must match the names of the WBP Blueprint menu buttons/fields/etc (widgets)
	UPROPERTY(meta = (BindWidget))
	class UButton* DisconnectButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* CancelButton;

	IMenuInterface* MenuInterface;

	UFUNCTION()
	void Disconnect();


};
