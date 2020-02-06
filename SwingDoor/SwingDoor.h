// Harrison McGuire
// UE4 Version 4.24.2
// https://github.com/Harrison1
// https://unrealcpp.com

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SwingDoor.generated.h"

UCLASS()
class UCPP_API ASwingDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASwingDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	class UStaticMeshComponent* Door;

	// declare sphere comp
	UPROPERTY(VisibleAnywhere, Category = "BoxComp")
	class UBoxComponent* BoxComp;

	bool Opening = false;
	bool Closing = false;
	bool isClosed = true;

	float DotP = 0.f;
	float MaxDegree = 0.f;
	float AddRotation = 0.f;
	float PosNeg = 0.f;
	float DoorCurrentRotation = 0.f;

	UFUNCTION()
	void OpenDoor(float dt);

	UFUNCTION()
	void CloseDoor(float dt);

	UFUNCTION()
	void ToggleDoor(FVector ForwardVector);
};
