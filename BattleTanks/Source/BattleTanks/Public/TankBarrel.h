// #Battle Tanks is an open world TPS developed and modified by Mod_V93

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max ddown speed and +1 is max up speed 
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 10.f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 40.f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0.f; 
};
