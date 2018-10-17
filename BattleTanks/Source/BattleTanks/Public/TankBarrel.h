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
	void Elevate(float DegreesPerSecond);
//Fulfill comiit
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20.f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 40.f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0.f; 
};
