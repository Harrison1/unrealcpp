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

#include "OpenDoorTimelineOverlap.h"
#include "Components/TimelineComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AOpenDoorTimelineOverlap::AOpenDoorTimelineOverlap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Open = false;

    MyBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("My Box Component"));
    MyBoxComponent->InitBoxExtent(FVector(50,50,50));
    RootComponent = MyBoxComponent;

    Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Mesh"));
    Door->SetRelativeLocation(FVector(0.0f, 50.0f, -50.0f));
    Door->SetupAttachment(RootComponent);

    MyBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AOpenDoorTimelineOverlap::OnOverlapBegin);
    MyBoxComponent->OnComponentEndOverlap.AddDynamic(this, &AOpenDoorTimelineOverlap::OnOverlapEnd);

}

// Called when the game starts or when spawned
void AOpenDoorTimelineOverlap::BeginPlay()
{
	Super::BeginPlay();

    RotateValue = 1.0f;

    if (OpenCurve)
    {
        FOnTimelineFloat TimelineCallback;
        TimelineCallback.BindUFunction(this, FName("ControlDoor"));

		MyTimeline = NewObject<UTimelineComponent>(this, FName("DoorAnimation"));
        MyTimeline->AddInterpFloat(OpenCurve, TimelineCallback);
		MyTimeline->RegisterComponent();
    }
}

// Called every frame
void AOpenDoorTimelineOverlap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

   	if (MyTimeline != NULL)
	{
		MyTimeline->TickComponent(DeltaTime, ELevelTick::LEVELTICK_TimeOnly, NULL);
	}
}

void AOpenDoorTimelineOverlap::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if ( (OtherActor != nullptr ) && (OtherActor != this) && ( OtherComp != nullptr ) ) 
    {

        FVector PawnLocation = OtherActor->GetActorLocation();
        FVector Direction = GetActorLocation() - PawnLocation;
        Direction = UKismetMathLibrary::LessLess_VectorRotator(Direction, GetActorRotation());

        if(Direction.X > 0.0f)
        {
            RotateValue = 1.0f;
        }
        else
        {
            RotateValue = -1.0f;
        }

        DoorRotation = Door->RelativeRotation;
		UE_LOG(LogTemp, Warning, TEXT("I just started running"));
		Open = true;
		if (MyTimeline != NULL)
		{
			MyTimeline->PlayFromStart();
		}
	}
}

void AOpenDoorTimelineOverlap::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if ( (OtherActor != nullptr ) && (OtherActor != this) && ( OtherComp != nullptr ) )  
    {
        DoorRotation = Door->RelativeRotation;

		Open = false;
		if (MyTimeline != NULL)
		{
			MyTimeline->Reverse();
		}
    }
}

void AOpenDoorTimelineOverlap::ControlDoor(float Value)
{
    if(Open) 
    {
        TimelineValue = MyTimeline->GetPlaybackPosition();
        CurveFloatValue = RotateValue*OpenCurve->GetFloatValue(TimelineValue);

        FQuat NewRotation = FQuat(FRotator(0.f, CurveFloatValue, 0.f));

        if (GEngine) 
        { 
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Timeline Value: %f"), CurveFloatValue));
        }

        Door->SetRelativeRotation(NewRotation);
    }
    else 
    {
        TimelineValue = MyTimeline->GetPlaybackPosition();
        CurveFloatValue = RotateValue*OpenCurve->GetFloatValue(TimelineValue);

        FQuat NewRotation = FQuat(FRotator(0.f, CurveFloatValue, 0.f));

        if (GEngine) 
        { 
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Timeline Value: %f"), CurveFloatValue));
        }

        Door->SetRelativeRotation(NewRotation);
    }
}
