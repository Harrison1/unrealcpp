// Harrison McGuire// UE4 Version 4.20.3// https://github.com/Harrison1/unrealcpp// https://severallevels.io// https://harrisonmcguire.com

#include "ShooterProjectile.h"


// Sets default values
AShooterProjectile::AShooterProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShooterProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShooterProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

