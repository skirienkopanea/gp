// Copyright Epic Games, Inc. All Rights Reserved.

#include "GardenGameMode.h"
#include "GardenCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGardenGameMode::AGardenGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
