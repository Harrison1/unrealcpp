// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#include "SetActorLocationAndRotation.h"

// Called when the game starts or when spawned
void ASetActorLocationAndRotation::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocationAndRotation(NewLocation, NewRotation, false, 0, ETeleportType::None);	
}
