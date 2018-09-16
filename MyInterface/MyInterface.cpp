// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#include "MyInterface.h"


// Add default functionality here for any IMyInterface functions that are not pure virtual.
void IMyInterface::SaySomething() 
{
    UE_LOG(LogTemp, Warning, TEXT("Hi %s"), *Name);
}

void IMyInterface::ReactToTriggerBegin()
{
    UE_LOG(LogTemp, Warning, TEXT("Enter the Trigger"));
}

void IMyInterface::ReactToTriggerEnd()
{
    UE_LOG(LogTemp, Warning, TEXT("Exit the Trigger"));
}