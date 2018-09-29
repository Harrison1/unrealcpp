// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#pragma once

#include "GameFramework/Actor.h"
#include "AddBillboardComp.generated.h"

UCLASS()
class UNREALCPP_API AAddBillboardComp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAddBillboardComp();

	// declare point billboard comp
	UPROPERTY(VisibleAnywhere)
	class UBillboardComponent* MyBillboardComp;
	
};
