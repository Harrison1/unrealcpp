// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#include "AddMeshFromFile.h"
// add constructor header
#include "UObject/ConstructorHelpers.h"

// Sets default values
AAddMeshFromFile::AAddMeshFromFile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// add Cylinder to root
    UStaticMeshComponent* Cylinder = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
    RootComponent = Cylinder;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder"));

	if (CylinderAsset.Succeeded())
    {
        Cylinder->SetStaticMesh(CylinderAsset.Object);
        Cylinder->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
        Cylinder->SetWorldScale3D(FVector(1.f));
	}
}
