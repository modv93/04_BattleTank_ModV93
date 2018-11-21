// #Battle Tanks is an open world TPS developed and modified by Mod_V93

#include "TankBarrel.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	//Move the barrel right amount this frame 
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevate = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevate, 0.f, 0.f));
}


