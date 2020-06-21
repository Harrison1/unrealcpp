// Unreal Version 4.25.1 


#include "DestroyActorOnOverlap.h"
#include "Components/SphereComponent.h"

// Sets default values
ADestroyActorOnOverlap::ADestroyActorOnOverlap()
{
	MySphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("My Sphere Component"));
	MySphereComponent->InitSphereRadius(100.f);
	MySphereComponent->SetCollisionProfileName(TEXT("Trigger"));
	RootComponent = MySphereComponent;

	MySphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ADestroyActorOnOverlap::OnOverlapBegin);
}

void ADestroyActorOnOverlap::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Destroy();
}
