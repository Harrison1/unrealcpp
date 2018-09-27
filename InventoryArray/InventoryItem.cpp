// Harrison McGuire
// UE4 Version 4.20.3
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#include "InventoryItem.h"

// Sets default values
AInventoryItem::AInventoryItem()
{

  InventoryItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InventoryItem Mesh"));
  InventoryItemMesh->SetSimulatePhysics(true);
  RootComponent = InventoryItemMesh;

  InventoryItemTexture = CreateDefaultSubobject<UTexture2D>(TEXT("InventoryItem Texture"));

  isGlowing = false;

}

// Called when the game starts or when spawned
void AInventoryItem::BeginPlay()
{
	Super::BeginPlay();

  InitialMaterial = InventoryItemMesh->GetMaterial(0);

  DynamicMatInstance = InventoryItemMesh->CreateAndSetMaterialInstanceDynamic(0);

  if(InventoryItemMesh->GetStaticMesh() && DynamicMatInstance) 
  {
    UE_LOG(LogTemp, Warning, TEXT("I have a mesh and material"));
  } 
  else
  {
    UE_LOG(LogTemp, Warning, TEXT("I am missing either the mesh or material"));
  }
}

void AInventoryItem::BeginFocus()
{
  if(InventoryItemMesh->GetStaticMesh() && DynamicMatInstance) 
  {
    DynamicMatInstance->SetScalarParameterValue(FName("EmissiveParam"), 50.0f);
  }
}

void AInventoryItem::EndFocus()
{
  if(InventoryItemMesh->GetStaticMesh() && DynamicMatInstance) 
  {
    DynamicMatInstance->SetScalarParameterValue(FName("EmissiveParam"), 0.0f);
  }
}

FString AInventoryItem::MyName()
{
  return InventoryItemName;
}
