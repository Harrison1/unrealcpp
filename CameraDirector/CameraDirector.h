// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#pragma once

#include "GameFramework/Actor.h"
#include "CameraDirector.generated.h"

UCLASS()
class UNREALCPP_API ACameraDirector : public AActor
{
	GENERATED_BODY()

public:	
	ACameraDirector();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// declare variables
	UPROPERTY(EditAnywhere)
	AActor* CameraOne;

	UPROPERTY(EditAnywhere)
	AActor* CameraTwo;

	float TimeToNextCameraChange;
	
};
