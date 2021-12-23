// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.h"

UMyGameInstance::UMyGameInstance(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/Menu/WBP_MainMenu"));

	if (!ensure(MenuBPClass.Class != nullptr)) return;
	
	MenuClass = MenuBPClass.Class;

	//load binding esc to show menu at some point
	
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