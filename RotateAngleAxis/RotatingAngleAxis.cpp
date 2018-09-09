// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#include "RotatingAngleAxis.h"


// Sets default values
ARotatingAngleAxis::ARotatingAngleAxis()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Dimensions = FVector (300, 0, 0);
	AxisVector = FVector (0, 0, 1);
	Multiplier = 50.f;
}

// Called every frame
void ARotatingAngleAxis::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = FVector (0,0,800);

	AngleAxis += DeltaTime * Multiplier;

	if(AngleAxis >= 360.0f) AngleAxis = 0;
	
	FVector RotateValue = Dimensions.RotateAngleAxis(AngleAxis, AxisVector);

	if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("RotateValue: %s"), *RotateValue.ToString()));	
	if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("AngleAxis: %f"), AngleAxis));

	NewLocation.X += RotateValue.X;
	NewLocation.Y += RotateValue.Y;
	NewLocation.Z += RotateValue.Z;

	SetActorLocation(NewLocation, false, 0, ETeleportType::None);
}
