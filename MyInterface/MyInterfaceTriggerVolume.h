// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "MyInterfaceTriggerVolume.generated.h"


UCLASS()
class UNREALCPP_API AMyInterfaceTriggerVolume : public ATriggerVolume
{
	GENERATED_BODY()

public:
	AMyInterfaceTriggerVolume();

	// overlap begin function
	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	// overlap end function
	UFUNCTION()
	void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
};
