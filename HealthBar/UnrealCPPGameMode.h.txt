// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "UnrealCPPGameMode.generated.h"

class AUnrealCPPCharacter;

//enum to store the current state of gameplay
UENUM()
enum class EGamePlayState
{
	EPlaying,
	EGameOver,
	EUnknown
};

UCLASS(minimalapi)
class AUnrealCPPGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AUnrealCPPGameMode();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	AUnrealCPPCharacter* MyCharacter;
	
	/** Returns the current playing state */
	UFUNCTION(BlueprintPure, Category = "Health")
	EGamePlayState GetCurrentState() const;

	/** Sets a new playing state */
	void SetCurrentState(EGamePlayState NewState);

	UPROPERTY(EditAnywhere, Category = "Health")
	TSubclassOf<class UUserWidget> HUDWidgetClass;

	UPROPERTY(EditAnywhere, Category = "Health")
	class UUserWidget* CurrentWidget;

private: 
	/**Keeps track of the current playing state */
	EGamePlayState CurrentState;

	/**Handle any function calls that rely upon changing the playing state of our game */
	void HandleNewState(EGamePlayState NewState);
};
