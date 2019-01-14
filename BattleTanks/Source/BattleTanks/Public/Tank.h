// #Battle Tanks is an open world TPS developed and modified by Mod_V93

#pragma once

//#include "TankAimingComponent.h"
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()
	
private:
	// Sets default values for this pawn's properties
	ATank();
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth = StartingHealth;

public:
	// called by the engine when the damage is dealt 
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController * EventInstigator, AActor * DamageCauser ) override;
	
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercentage() const;

	FTankDelegate OnDeath;
};
