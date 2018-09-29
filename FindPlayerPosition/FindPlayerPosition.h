// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#pragma once

#include "GameFramework/Actor.h"
#include "FindPlayerPosition.generated.h"

UCLASS()
class UNREALCPP_API AFindPlayerPosition : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFindPlayerPosition();

	// Called every frame
	virtual void Tick(float DeltaTime) override;	
	
};
