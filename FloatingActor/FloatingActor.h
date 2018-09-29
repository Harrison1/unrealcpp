// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#pragma once

#include "GameFramework/Actor.h"
#include "FloatingActor.generated.h"

UCLASS()
class UNREALCPP_API AFloatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingActor();
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// declare our float variables 
	float RunningTime;
	
	UPROPERTY(EditAnywhere, Category = Movement)
	float XValue;

	UPROPERTY(EditAnywhere, Category = Movement)
	float YValue;

	UPROPERTY(EditAnywhere, Category = Movement)
	float ZValue;
};
