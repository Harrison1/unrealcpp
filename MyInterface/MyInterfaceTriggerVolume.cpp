// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#include "MyInterfaceTriggerVolume.h"
#include "Kismet/GameplayStatics.h"
#include "MyInterface.h"

AMyInterfaceTriggerVolume::AMyInterfaceTriggerVolume()
{
    OnActorBeginOverlap.AddDynamic(this, &AMyInterfaceTriggerVolume::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this, &AMyInterfaceTriggerVolume::OnOverlapEnd);
}

void AMyInterfaceTriggerVolume::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
    // check if Actors do not equal nullptr and that 
    if (OtherActor && OtherActor != this && !Cast<AMyInterfaceActor>(OtherActor)) 
    {
        TArray<AActor*> MyInterfaceActors;
        UGameplayStatics::GetAllActorsWithInterface(GetWorld(), UMyInterface::StaticClass(), MyInterfaceActors);

        if(MyInterfaceActors.Num() > 0)
        {
            for (auto& Act : MyInterfaceActors)
            {
                IMyInterface* InterfaceActor = Cast<IMyInterface>(Act);
                if(InterfaceActor)
                {
                    InterfaceActor->SaySomething();
                    InterfaceActor->ReactToTriggerBegin();
                }
            }
        }
    }
}

void AMyInterfaceTriggerVolume::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && OtherActor != this && !Cast<AMyInterfaceActor>(OtherActor)) 
    {
        TArray<AActor*> MyInterfaceActors;
        UGameplayStatics::GetAllActorsWithInterface(GetWorld(), UMyInterface::StaticClass(), MyInterfaceActors);

        if(MyInterfaceActors.Num() > 0)
        {
            for (auto& Act : MyInterfaceActors)
            {
                IMyInterface* InterfaceActor = Cast<IMyInterface>(Act);
                if(InterfaceActor)
                {
                    InterfaceActor->ReactToTriggerEnd();
                }
            }
        }
    }
}
