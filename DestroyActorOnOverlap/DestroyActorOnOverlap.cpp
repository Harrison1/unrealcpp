// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#include "DestroyActorOnOverlap.h"


// Sets default values
// add a mesh in the editor and set Collision Presets to Trigger
ADestroyActorOnOverlap::ADestroyActorOnOverlap()
{
	OnActorBeginOverlap.AddDynamic(this, &ADestroyActorOnOverlap::OnOverlap);
}

void ADestroyActorOnOverlap::OnOverlap(AActor* MyOverlappedActor, AActor* OtherActor)
{
	Destroy();
}
