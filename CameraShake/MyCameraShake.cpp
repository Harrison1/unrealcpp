// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#include "MyCameraShake.h"

// Helpful Links
// http://api.unrealengine.com/INT/API/Runtime/Engine/Camera/UCameraShake/index.html
//
// Great explanation of camera shake values
// https://www.youtube.com/watch?v=Oice8gdpX6s

#include "MyCameraShake.h"

// Sets default values
UMyCameraShake::UMyCameraShake()
{
    OscillationDuration = 0.25f;
    OscillationBlendInTime = 0.05f;
    OscillationBlendOutTime = 0.05f;

    RotOscillation.Pitch.Amplitude = FMath::RandRange(5.0f, 10.0f);
    RotOscillation.Pitch.Frequency = FMath::RandRange(25.0f, 35.0f);

    RotOscillation.Yaw.Amplitude = FMath::RandRange(5.0f, 10.0f);
    RotOscillation.Yaw.Frequency = FMath::RandRange(25.0f, 35.0f);
}
