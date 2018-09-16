// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#include "MyInterfaceActor.h"
#include "Components/TimelineComponent.h"

// Sets default values
AMyInterfaceActor::AMyInterfaceActor()
{
	MyTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("My Timeline"));

	Name = FString(TEXT("Harry"));
}

void AMyInterfaceActor::SaySomething() 
{
	IMyInterface::SaySomething();
	
	FVector PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

	if (MyCurve) 
	{
		FOnTimelineFloat TimelineCallback;
		TimelineCallback.BindUFunction(this, FName("MoveToLocation"));
		MyTimeline->AddInterpFloat(MyCurve, TimelineCallback);
		MyTimeline->SetLooping(false);
		Start = GetActorLocation();
		MyTimeline->PlayFromStart();
	}
}

void AMyInterfaceActor::MoveToLocation(float value) 
{
	UE_LOG(LogTemp, Error, TEXT("Hello Galaxy: %f"), value);	
	End = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	SetActorLocation(FMath::Lerp(Start, End, value));
}
