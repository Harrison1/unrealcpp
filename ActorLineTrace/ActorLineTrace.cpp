// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#include "ActorLineTrace.h"
#include "ConstructorHelpers.h"
#include "DrawDebugHelpers.h"

// Sets default values
AActorLineTrace::AActorLineTrace()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// add cube to root
    Cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Visual Representation"));
    RootComponent = Cube;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if (CubeAsset.Succeeded())
    {
        Cube->SetStaticMesh(CubeAsset.Object);
        Cube->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
        Cube->SetWorldScale3D(FVector(1.f));
	}
	
	// add another component in the editor to the actor to overlap with the line trace to get the event to fire

}

// Called every frame
void AActorLineTrace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult OutHit;
	FVector Start = GetActorLocation();

	Start.Z += 50.f;
	Start.X += 200.f;

	FVector ForwardVector = GetActorForwardVector();
	FVector End = ((ForwardVector * 500.f) + Start);
	FCollisionQueryParams CollisionParams;
	CollisionParams.bTraceComplex = true;
	CollisionParams.AddIgnoredComponent(Cube);
	// or use the below to ignore the component
	// CollisionParams.AddIgnoredComponent_LikelyDuplicatedRoot(Cube);

	DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1, 0, 5);

	if(ActorLineTraceSingle(OutHit, Start, End, ECC_WorldStatic, CollisionParams))
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("The Component Being Hit is: %s"), *OutHit.GetComponent()->GetName()));
	}

}
