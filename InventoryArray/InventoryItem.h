// Harrison McGuire
// UE4 Version 4.20.3
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#pragma once

#include "GameFramework/Actor.h"
#include "InventoryItem.generated.h"

UCLASS()
class UNREALCPP_API AInventoryItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInventoryItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

  UPROPERTY(EditAnywhere, Category = InventoryItem)
  class UStaticMeshComponent* InventoryItemMesh;

  UPROPERTY(EditAnywhere, Category = InventoryItem)
  class UTexture2D* InventoryItemTexture;

  UPROPERTY(EditAnywhere, Category = InventoryItem)
  FString InventoryItemName;

  UPROPERTY(EditAnywhere, Category = InventoryItem)
  class UMaterialInterface* InitialMaterial;

  UPROPERTY(EditAnywhere, Category = InventoryItem)
  class UMaterialInterface* GlowMaterial;

  UPROPERTY(EditAnywhere, Category = InventoryItem)
  class UMaterialInstanceDynamic* DynamicMatInstance;

  UPROPERTY(EditAnywhere, Category = InventoryItem)
  bool isGlowing;

  UFUNCTION()
  void BeginFocus();

  UFUNCTION()
  void EndFocus();

  UFUNCTION()
  FString MyName();

  FORCEINLINE UTexture2D* GetInventoryItemTexture() { return InventoryItemTexture; }
	
};

