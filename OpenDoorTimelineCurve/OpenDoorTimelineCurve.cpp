// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

// helpful links
// https://docs.unrealengine.com/latest/INT/API/Runtime/Engine/Components/FTimeline/
// https://docs.unrealengine.com/latest/INT/API/Runtime/Engine/Components/UTimelineComponent/index.html
// https://wiki.unrealengine.com/Timeline_in_c%2B%2B#How_to_use_Timeline_in_C.2B.2B
// https://docs.unrealengine.com/latest/INT/API/Runtime/Engine/Curves/UCurveFloat/GetFloatValue/index.html
// https://docs.unrealengine.com/latest/INT/API/Runtime/Engine/Curves/UCurveFloat/
// https://docs.unrealengine.com/latest/INT/API/Runtime/Engine/Components/UPrimitiveComponent/OnComponentBeginOverlap/
// https://docs.unrealengine.com/latest/INT/API/Runtime/Engine/Components/UPrimitiveComponent/OnComponentEndOverlap/
// https://docs.unrealengine.com/latest/INT/BlueprintAPI/Math/Vector/UnrotateVector/
// https://docs.unrealengine.com/latest/INT/API/Runtime/Engine/Kismet/UKismetMathLibrary/LessLess_VectorRotator/index.html
// https://docs.unrealengine.com/latest/INT/API/Runtime/Engine/Kismet/UKismetMathLibrary/index.html

#include "OpenDoorTimelineCurve.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TimelineComponent.h"

// Sets default values
AOpenDoorTimelineCurve::AOpenDoorTimelineCurve()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Open = false;
    ReadyState = true;

    DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
    RootComponent = DoorFrame;

    Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Mesh"));
    Door->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AOpenDoorTimelineCurve::BeginPlay()
{
	Super::BeginPlay();

	RotateValue = 1.0f;

    if (DoorCurve)
    {
        FOnTimelineFloat TimelineCallback;
        FOnTimelineEventStatic TimelineFinishedCallback;

        TimelineCallback.BindUFunction(this, FName("ControlDoor"));
        TimelineFinishedCallback.BindUFunction(this, FName("SetState"));

        MyTimeline = NewObject<UTimelineComponent>(this, FName("DoorAnimation"));
        MyTimeline->AddInterpFloat(DoorCurve, TimelineCallback);
        MyTimeline->SetTimelineFinishedFunc(TimelineFinishedCallback);        
		MyTimeline->RegisterComponent();
    }
	
}

// Called every frame
void AOpenDoorTimelineCurve::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

   	if (MyTimeline != NULL)
	{
	    MyTimeline->TickComponent(DeltaTime, ELevelTick::LEVELTICK_TimeOnly, NULL);
    }
}

void AOpenDoorTimelineCurve::ControlDoor()
{
    TimelineValue = MyTimeline->GetPlaybackPosition();
    CurveFloatValue = RotateValue*DoorCurve->GetFloatValue(TimelineValue);

    FQuat NewRotation = FQuat(FRotator(0.f, CurveFloatValue, 0.f));

    Door->SetRelativeRotation(NewRotation);
}

void AOpenDoorTimelineCurve::SetState()
{
    ReadyState = true;
}

void AOpenDoorTimelineCurve::ToggleDoor() 
{
    if(ReadyState) 
    {
        Open = !Open;

        // alternative way to get pawn position
        // GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation()
        APawn* OurPawn = UGameplayStatics::GetPlayerPawn(this, 0);
        FVector PawnLocation = OurPawn->GetActorLocation();
        FVector Direction = GetActorLocation() - PawnLocation;
        Direction = UKismetMathLibrary::LessLess_VectorRotator(Direction, GetActorRotation());

        if(Open)
        {     
            if(Direction.X > 0.0f)
            {
                RotateValue = 1.0f;
            }
            else
            {
                RotateValue = -1.0f;
            }

            ReadyState = false;
            if (MyTimeline != NULL)
	        {
                MyTimeline->PlayFromStart();
            }
        }
        else 
        {
            ReadyState = false;
            if (MyTimeline != NULL)
	        {
                MyTimeline->Reverse();
            }
        }
    }
}
