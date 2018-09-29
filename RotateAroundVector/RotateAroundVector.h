// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#pragma once

#include "GameFramework/Actor.h"
#include "RotateAroundVector.generated.h"

UCLASS()
class UNREALCPP_API ARotateAroundVector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotateAroundVector();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// declare our variable for the angle axis
	float AngleAxis;
};
