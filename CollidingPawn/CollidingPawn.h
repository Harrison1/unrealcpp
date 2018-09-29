// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#pragma once

#include "GameFramework/Pawn.h"
#include "CollidingPawn.generated.h"

UCLASS()
class UNREALCPP_API ACollidingPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACollidingPawn();

public:	
	// Called every frame
    virtual void Tick( float DeltaSeconds ) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

    UParticleSystemComponent* OurParticleSystem;
    class UCollidingPawnMovementComponent* OurMovementComponent;

    virtual UPawnMovementComponent* GetMovementComponent() const override;

    void MoveForward(float AxisValue);
    void MoveRight(float AxisValue);
    void Turn(float AxisValue);
    void ParticleToggle();
};
