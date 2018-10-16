// #Battle Tanks is an open world TPS developed and modified by Mod_V93

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Classes/Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankAimingComponent.generated.h"

// Forward Declaration - Basically, decalres a class in this scope without including chain of dependencies. Use only if no memeber functions are required

class  UTankBarrel; // Holds Barrels prroperties and elevate method

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	//TODO Set Turret reference
	void SetBarrelReference(UTankBarrel* BarrelToSet);
protected:

public:	
	void AimAt(FVector Hitlocation, float LaunchSpeed);
	
	
private:
	UTankBarrel * Barrel = nullptr;
	void MoveBarrelTowards(FVector AimDirection);
};
