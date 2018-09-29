// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#pragma once

#include "GameFramework/Actor.h"
#include "ConsoleLog.generated.h"

UCLASS()
class UNREALCPP_API AConsoleLog : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConsoleLog();

	UPROPERTY(EditAnywhere)
	class USceneComponent* DefaultSceneComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
