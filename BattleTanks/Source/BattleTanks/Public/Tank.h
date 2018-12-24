// #Battle Tanks is an open world TPS developed and modified by Mod_V93

#pragma once

//#include "TankAimingComponent.h"
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Fire();
protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent * TankAimingComponent = nullptr;
	
private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint; 

	//TODO Remove once Fire is moved Aiming component 
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 5000.f; //TODO find sensible default value

	UPROPERTY(EditDefaultsOnly, Category = "Firing") //Use EditDefaultsOnly to make it tweekable for all tanks by default
	float ReloadTimeInSeconds = 3.f; //TODO find sensible default value

	//TODO Remove
	UTankBarrel* Barrel = nullptr; // Local barrel reference for projectile spawning 
	
	float LastFireTime = 0.f;
	
};
