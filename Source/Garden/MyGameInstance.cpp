// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.h"
#include "InGameMenu.h"

UMyGameInstance::UMyGameInstance(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/Menu/WBP_MainMenu"));

	if (!ensure(MenuBPClass.Class != nullptr)) return;
	
	MenuClass = MenuBPClass.Class;

	//Make sure to also set as parent for WBP_InGameMenu (from UE4 editor GUI) InGameMenu
	ConstructorHelpers::FClassFinder<UUserWidget> InGameMenuBPClass(TEXT("/Game/Menu/WBP_InGameMenu"));

	if (!ensure(InGameMenuBPClass.Class != nullptr)) return;

	InGameMenuClass = InGameMenuBPClass.Class;
}

void UMyGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Found class %s"),*MenuClass->GetName());

}

void UMyGameInstance::LoadMenu() {
	if (!ensure(MenuClass != nullptr)) return;
	Menu = CreateWidget<UMainMenu>(this, MenuClass);

	if (!ensure(Menu != nullptr)) return;
	Menu->bIsFocusable = true;

	
	Menu->Setup();
	Menu->SetMenuInterface(this); //this allows us to use the commands below as callable menu interface functions

}

void UMyGameInstance::LoadInGameMenu() {
	if (!ensure(InGameMenuClass != nullptr)) return;
	InGameMenu = CreateWidget<UInGameMenu>(this, InGameMenuClass);

	if (!ensure(InGameMenu != nullptr)) return;
	InGameMenu->bIsFocusable = true;


	InGameMenu->Setup();
	InGameMenu->SetMenuInterface(this);

}

void UMyGameInstance::Host()
{

	UEngine* Engine = GEngine;
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/Room/Levels/Room?listen");

}

void UMyGameInstance::Join(const FString& Address)
{
	UEngine* Engine = GEngine;
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return; //use this for binding things even if the game is run directly as a server without a player

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}

void UMyGameInstance::LoadMainMenu()
{
	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return; //use this for binding things even if the game is run directly as a server without a player

	PlayerController->ClientTravel("/Game/Room/Levels/Menu", ETravelType::TRAVEL_Absolute);

}