// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CreateStaticMesh.generated.h"

UCLASS()
class UNREALCPP_API ACreateStaticMesh : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACreateStaticMesh();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SuperMesh;
};
