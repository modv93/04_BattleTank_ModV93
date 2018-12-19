// #Battle Tanks is an open world TPS developed and modified by Mod_V93.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = .5f; 
	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.3333333f;
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.f;

protected: 
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;

private:
	void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	/*Start the tank moving it's barrel towards the crosshair, 
	so that the tank can shoot at the position where the barrel intersects with crosshair*/
	void AimTowardsCrossHair(); 

	//Return an out parameter, true if it hits the landscape
	bool GetSightRayHitLocation(FVector& Hitlocation) const;
	bool GetLookDirection(FVector2D , FVector& ) const;
	bool GetLookVectoHitLocation(FVector, FVector&) const;
};
