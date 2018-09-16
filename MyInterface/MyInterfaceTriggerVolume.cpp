// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#include "MyInterfaceTriggerVolume.h"
#include "Kismet/GameplayStatics.h"
#include "MyInterface.h"
#include "MyInterfaceActor.h"

AMyInterfaceTriggerVolume::AMyInterfaceTriggerVolume()
{
    OnActorBeginOverlap.AddDynamic(this, &AMyInterfaceTriggerVolume::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this, &AMyInterfaceTriggerVolume::OnOverlapEnd);
}

void AMyInterfaceTriggerVolume::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
    // check if Actors do not equal nullptr and that 
    if (OtherActor && OtherActor != this) 
    {
        TArray<AActor*> MyInterfaceActors;
        UGameplayStatics::GetAllActorsWithInterface(GetWorld(), UMyInterface::StaticClass(), MyInterfaceActors);

        if(MyInterfaceActors.Num() > 0)
        {
            for (auto& Act : MyInterfaceActors)
            {
	            UE_LOG(LogTemp, Warning, TEXT("Actor Name: %s"), *Act->GetName());
                AMyInterfaceActor* Meme = Cast<AMyInterfaceActor>(Act);
                Meme->SaySomething();
            }
        }
    }
}

void AMyInterfaceTriggerVolume::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && OtherActor != this) 
    {

    }
}
