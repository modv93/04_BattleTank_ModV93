// #Battle Tanks is an open world TPS developed and modified by Mod_V93

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Classes/Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};
//Forward Declare
class UTankBarrel; 
class UTankTurret;

//Holds Parameters for barrels 
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet);

	// Sets default values for this component's properties
	UTankAimingComponent();
protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FireState = EFiringState::Aiming;


public:	
	void AimAt(FVector Hitlocation, float LaunchSpeed);
	
private:
	UTankBarrel * Barrel = nullptr;
	UTankTurret * Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};
