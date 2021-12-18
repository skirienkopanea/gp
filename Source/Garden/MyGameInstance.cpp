// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Engine/Engine.h"

UMyGameInstance::UMyGameInstance(const FObjectInitializer& ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance constructor"));
}

void UMyGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Init constructor"));
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

void UMyGameInstance:: Join(const FString& Address)
{
	UEngine* Engine = GEngine;
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return; //use this for binding things even if the game is run directly as a server without a player

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}