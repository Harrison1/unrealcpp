// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#include "RotateAroundVector.h"


// Sets default values
ARotateAroundVector::ARotateAroundVector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AngleAxis = 0;
}

// Called every frame
void ARotateAroundVector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// declare arbitrary vector point in the world to circle around
	FVector NewLocation = FVector (0,0,800);

	// declare size of radius to move around
	FVector Radius = FVector(200,0,0);

	// angle increases by 1 every frame
	AngleAxis++;

	// prevent number from growind indefinitely
	if(AngleAxis > 360.0f) AngleAxis = 1;

	FVector RotateValue = Radius.RotateAngleAxis(AngleAxis, FVector (0,0,1));

	NewLocation.X += RotateValue.X;
	NewLocation.Y += RotateValue.Y;
	NewLocation.Z += RotateValue.Z;
	
	SetActorLocation(NewLocation);

}
