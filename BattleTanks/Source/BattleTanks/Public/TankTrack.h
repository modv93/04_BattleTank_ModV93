// #Battle Tanks is an open world TPS developed and modified by Mod_V93

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

class ASprungWheel;
/**
 * TankTrack is a static mesh component used to apply force for moving the tank. 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// Sets a throttle speed between -1 and +1
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	//Max force per track in newtons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 400000.f;
	// 40,000 KG tank and 1G accelaration

private:	
	UTankTrack();

	TArray<ASprungWheel*> GetWheels() const;
	void DriveTrack(float CurrentThrottle);

	/*
	Changes made for applying force directly on wheels, physics forces setup on the wheels. Change Identifier : TRACK_FORCE
	virtual void BeginPlay() override;
	void ApplySidewaysForce();

	UFUNCTION()
	void OnHit(UPrimitiveComponent * HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
				FVector NormalImpulse, const FHitResult& Hit);
	*/
	
};
