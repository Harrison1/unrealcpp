// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#pragma once

#include "GameFramework/Actor.h"
#include "TimerActor.generated.h"

UCLASS()
class UNREALCPP_API ATimerActor : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	void RepeatingFunction();
	
	struct FTimerHandle MemberTimerHandle;
};
