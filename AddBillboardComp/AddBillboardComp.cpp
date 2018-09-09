// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#include "AddBillboardComp.h"
// include billboard comp
#include "Components/BillboardComponent.h"

// Sets default values
AAddBillboardComp::AAddBillboardComp()
{
	MyBillboardComp = CreateDefaultSubobject<UBillboardComponent>(TEXT("Root Billboard Comp"));
	MyBillboardComp->SetHiddenInGame(false, true);
	RootComponent = MyBillboardComp;
}
