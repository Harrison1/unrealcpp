// Harrison McGuire
// UE4 Version 4.24.2
// https://github.com/Harrison1
// https://unrealcpp.com

// helpful links
// https://docs.unrealengine.com/latest/INT/API/Runtime/Engine/GameFramework/AActor/SetActorRelativeRotation/2/index.html
// https://docs.unrealengine.com/latest/INT/API/Runtime/Engine/Components/USceneComponent/GetComponentRotation/index.html
// https://docs.unrealengine.com/latest/INT/API/Runtime/Engine/Kismet/UKismetSystemLibrary/DrawDebugBox/
// https://docs.unrealengine.com/latest/INT/API/Runtime/Engine/DrawDebugBox/2/
// https://docs.unrealengine.com/latest/INT/API/Runtime/Core/Math/FVector/DotProduct/index.html
// https://docs.unrealengine.com/latest/INT/API/Runtime/Core/Math/FMath/
// https://docs.unrealengine.com/latest/INT/BlueprintAPI/Math/Float/Sign_float/

#include "SwingDoor.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/BoxComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASwingDoor::ASwingDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("My Box Component"));
	BoxComp->InitBoxExtent(FVector(150, 100, 100));
	BoxComp->SetCollisionProfileName("Trigger");
	RootComponent = BoxComp;

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> DoorAsset(TEXT("/Game/StarterContent/Props/SM_Door.SM_Door"));

	if (DoorAsset.Succeeded())
	{
		Door->SetStaticMesh(DoorAsset.Object);
		Door->SetRelativeLocation(FVector(0.0f, 50.0f, -100.0f));
		Door->SetWorldScale3D(FVector(1.f));
	}

}

// Called when the game starts or when spawned
void ASwingDoor::BeginPlay()
{
	Super::BeginPlay();

	DrawDebugBox(GetWorld(), GetActorLocation(), BoxComp->GetScaledBoxExtent(), FQuat(GetActorRotation()), FColor::Turquoise, true, 999, 0, 2);
}

// Called every frame
void ASwingDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Opening)
	{
		OpenDoor(DeltaTime);
	}

	if (Closing)
	{
		CloseDoor(DeltaTime);
	}

}

void ASwingDoor::OpenDoor(float dt)
{
	DoorCurrentRotation = Door->RelativeRotation.Yaw;

	AddRotation = PosNeg * dt * 80;

	if (FMath::IsNearlyEqual(DoorCurrentRotation, MaxDegree, 1.5f))
	{
		Closing = false;
		Opening = false;
	}
	else if (Opening)
	{
		FRotator NewRotation = FRotator(0.0f, AddRotation, 0.0f);
		Door->AddRelativeRotation(FQuat(NewRotation), false, 0, ETeleportType::None);
	}
}

void ASwingDoor::CloseDoor(float dt)
{
	DoorCurrentRotation = Door->RelativeRotation.Yaw;

	if (DoorCurrentRotation > 0)
	{
		AddRotation = -dt * 80;
	}
	else
	{
		AddRotation = dt * 80;
	}

	if (FMath::IsNearlyEqual(DoorCurrentRotation, 0.0f, 1.5f))
	{
		Closing = false;
		Opening = false;
	}
	else if (Closing)
	{
		FRotator NewRotation = FRotator(0.0f, AddRotation, 0.0f);
		Door->AddRelativeRotation(FQuat(NewRotation), false, 0, ETeleportType::None);
	}
}

void ASwingDoor::ToggleDoor(FVector ForwardVector)
{

	// alternatively you can grab the froward vector from the character inside theis function, remember to #include "GameFramework/Character.h" and #include "Camera/CameraComponent.h" at the top of the script
	// ACharacter* OurPlayerController = UGameplayStatics::GetPlayerCharacter(this, 0);

	// UCameraComponent* PlayerCamera = OurPlayerController->FindComponentByClass<UCameraComponent>();

	// FVector ForwardVector = PlayerCamera->GetForwardVector();

	// is the chacter in front or behind the door
	DotP = FVector::DotProduct(BoxComp->GetForwardVector(), ForwardVector);

	// get 1 or -1 from the the dot product
	PosNeg = FMath::Sign(DotP);

	// degree to clamp at
	MaxDegree = PosNeg * 90.0f;

	// toggle bools
	if (isClosed) {
		isClosed = false;
		Closing = false;
		Opening = true;

	}
	else {
		Opening = false;
		isClosed = true;
		Closing = true;
	}
}
