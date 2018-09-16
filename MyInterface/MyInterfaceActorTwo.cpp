// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#include "MyInterfaceActorTwo.h"
#include "Components/TimelineComponent.h"

// Sets default values
AMyInterfaceActorTwo::AMyInterfaceActorTwo()
{
	MyTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("My Timeline"));

	Name = FString(TEXT("Eddy"));
}

void AMyInterfaceActorTwo::MoveToLocation(float value) 
{
	SetActorLocation(FMath::Lerp(Start, End, value));
}

void AMyInterfaceActorTwo::ReactToTriggerBegin()
{
	IMyInterface::ReactToTriggerBegin();

	if (MyCurve) 
	{
		FOnTimelineFloat TimelineCallback;
		TimelineCallback.BindUFunction(this, FName("MoveToLocation"));
		MyTimeline->AddInterpFloat(MyCurve, TimelineCallback);
		MyTimeline->SetLooping(false);
		Start = GetActorLocation();
		End = Start*5;
		MyTimeline->PlayFromStart();
	}
}

void AMyInterfaceActorTwo::ReactToTriggerEnd()
{
	IMyInterface::ReactToTriggerEnd();

	if (MyCurve)
	{
		FOnTimelineFloat TimelineCallback;
		TimelineCallback.BindUFunction(this, FName("MoveToLocation"));
		MyTimeline->AddInterpFloat(MyCurve, TimelineCallback);
		MyTimeline->SetLooping(false);
		End = Start;
		Start = GetActorLocation();
		MyTimeline->PlayFromStart();
	}
}
