// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#pragma once

#include "UObject/Interface.h"
#include "MyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMyInterface : public UInterface
{
	GENERATED_BODY()
};


class UNREALCPP_API IMyInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	/** React to a trigger volume activating this object. Return true if the reaction succeeds. */
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Trigger Reaction")
    bool ReactToTrigger() const;

	virtual void SaySomething();

	virtual void ReactToTriggerBegin();
	virtual void ReactToTriggerEnd();

	FString Name;
};
