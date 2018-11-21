// #Battle Tanks is an open world TPS developed and modified by Mod_V93

#include "TankTurret.h"
#include "Engine/World.h"
void UTankTurret::Rotate(float RelativeSpeed)
{
	//Move the Turret right amount this frame 
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotate = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0.f, Rotate, 0.f));
}



