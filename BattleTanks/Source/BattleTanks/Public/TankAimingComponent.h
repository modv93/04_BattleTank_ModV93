// #Battle Tanks is an open world TPS developed and modified by Mod_V93

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Classes/Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	//TODO Set Turret reference
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);
protected:

public:	
	void AimAt(FVector Hitlocation, float LaunchSpeed);
	
	
private:
	UStaticMeshComponent * Barrel = nullptr;
	void MoveBarrelTowards(FVector AimDirection);
};
