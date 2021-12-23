// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"

bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(HostButton != nullptr)) return false;
	HostButton->OnClicked.AddDynamic(this, &UMainMenu::HostServer);

	if (!ensure(JoinButton != nullptr)) return false;
	JoinButton->OnClicked.AddDynamic(this, &UMainMenu::OpenJoinMenu);

	if (!ensure(CancelJoinButton != nullptr)) return false;
	CancelJoinButton->OnClicked.AddDynamic(this, &UMainMenu::OpenMainMenu);

	if (!ensure(OKJoinButton != nullptr)) return false;
	OKJoinButton->OnClicked.AddDynamic(this, &UMainMenu::JoinServer);

	if (!ensure(JoinKpanButton != nullptr)) return false;
	JoinKpanButton->OnClicked.AddDynamic(this, &UMainMenu::JoinOfficialGardenServer);

	return true;
}

void UMainMenu::SetMenuInterface(IMenuInterface* MI) {
	MenuInterface = MI;
}

void UMainMenu::Setup() {
	this->AddToViewport();

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;
	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(this->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = true;
}

void UMainMenu::Teardown()
{
	this->RemoveFromViewport();

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;
	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeGameOnly InputModeData;
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = false;

}

void UMainMenu::HostServer()
{
	//UE_LOG(LogTemp, Warning, TEXT("I'm gonna host a server"));
	if (MenuInterface != nullptr)
	{
		MenuInterface->Host();
		Teardown();
	}
	
}

void UMainMenu::OpenMainMenu()
{
	//UE_LOG(LogTemp, Warning, TEXT("I'm gonna host a server"));
	if (MenuInterface != nullptr)
	{
		if (!ensure(MenuSwitcher != nullptr)) return;
		if (!ensure(MainMenu != nullptr)) return;

		MenuSwitcher->SetActiveWidget(MainMenu);
	}

}

void UMainMenu::OpenJoinMenu()
{
	//UE_LOG(LogTemp, Warning, TEXT("I'm gonna host a server"));
	if (MenuInterface != nullptr)
	{
		if (!ensure(MenuSwitcher != nullptr)) return;
		if (!ensure(JoinMenu != nullptr)) return;

		MenuSwitcher->SetActiveWidget(JoinMenu);
	}

}

void UMainMenu::JoinServer()
{
	//UE_LOG(LogTemp, Warning, TEXT("I'm gonna host a server"));
	if (MenuInterface != nullptr)
	{
		if (!ensure(IPAddressField != nullptr)) return;
		const FString& Address = IPAddressField->GetText().ToString();
		MenuInterface->Join(Address);
		Teardown();
	}
}

void UMainMenu::JoinOfficialGardenServer()
{
	
	//UE_LOG(LogTemp, Warning, TEXT("I'm gonna host a server"));
	if (MenuInterface != nullptr)
	{
		MenuInterface->Join(TEXT("kpan.nl"));
		Teardown();
	}
}