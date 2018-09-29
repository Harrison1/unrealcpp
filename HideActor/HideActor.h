// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#pragma once

#include "GameFramework/Actor.h"
#include "HideActor.generated.h"

UCLASS()
class UNREALCPP_API AHideActor : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere, Category = "Disable")
	bool HideInGame;

	UFUNCTION(BlueprintCallable, Category = "Disable")
	void DisableActor(bool toHide);

};
