// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#include "CreateStaticMesh.h"


// Sets default values
ACreateStaticMesh::ACreateStaticMesh()
{
	// Add static mesh component to actor
	SuperMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Super Mesh"));
}
