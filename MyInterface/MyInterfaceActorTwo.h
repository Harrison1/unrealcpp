// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#pragma once

#include "CoreMinimal.h"
#include "MyInterface.h"
#include "GameFramework/Actor.h"
#include "MyInterfaceActorTwo.generated.h"

class UTimelineComponent;

UCLASS()
class UNREALCPP_API AMyInterfaceActorTwo : public AActor, public IMyInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyInterfaceActorTwo();

	// virtual void SaySomething() override;
	virtual void ReactToTriggerBegin() override;
	virtual void ReactToTriggerEnd() override;

	UPROPERTY(EditAnywhere)
	UCurveFloat* MyCurve;

	UPROPERTY(EditAnywhere)
	UTimelineComponent* MyTimeline;

	UPROPERTY()
	FVector Start;

	UPROPERTY()
	FVector End;

	UFUNCTION()
	void MoveToLocation(float value);
};
