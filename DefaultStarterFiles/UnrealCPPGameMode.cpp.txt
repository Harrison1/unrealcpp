// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "UnrealCPPGameMode.h"
#include "UnrealCPPHUD.h"
#include "UnrealCPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealCPPGameMode::AUnrealCPPGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AUnrealCPPHUD::StaticClass();
}
