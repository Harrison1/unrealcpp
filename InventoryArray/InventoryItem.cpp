// Harrison McGuire
// UE4 Version 4.20.3
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#include "InventoryItem.h"


// Sets default values
AInventoryItem::AInventoryItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInventoryItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInventoryItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

