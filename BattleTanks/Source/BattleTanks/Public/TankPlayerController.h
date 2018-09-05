// #Battle Tanks is an open world TPS developed and modified by Mod_V93.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	ATank* GetControlledTank() const;
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = .5f; 
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.3333333f;
private:
	/*Start the tank moving it's barrel towards the crosshair, 
	so that the tank can shoot at the position where the barrel intersects with crosshair*/
	void AimTowardsCrossHair(); 
	//Return an out parameter, true if it hits the landscape
	bool GetSightRayHitLocation(FVector& Hitlocation) const;
	
};
