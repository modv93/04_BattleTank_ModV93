// #Battle Tanks is an open world TPS developed and modified by Mod_V93

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	//How close the AI tank can get to the player tank
	UPROPERTY(EditAnywhere, Category = "Setup") // Consider EditDefaultsonly
	float AcceptanceRadius = 7000.f;
	
private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	 
};
