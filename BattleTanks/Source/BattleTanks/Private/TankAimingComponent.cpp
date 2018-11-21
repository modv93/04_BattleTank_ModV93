// #Battle Tanks is an open world TPS developed and modified by Mod_V93

#include "TankBarrel.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}


void UTankAimingComponent::AimAt(FVector Hitlocation, float LaunchSpeed)
{
	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		Hitlocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if(bHaveAimSolution)
	 //Calculate OutLaunchVelocity
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		//UE_LOG(LogTemp, Warning, TEXT("Aim solution found "), *AimDirection.ToString())
		MoveBarrelTowards(AimDirection);
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f Aim solution found "), Time)
	}
	else
	{
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f NO Aim solution found "), Time)
	}
}
void UTankAimingComponent::MoveBarrelTowards(FVector  AimDirection)
{
	auto barrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	//UE_LOG(LogTemp, Warning, TEXT("AimAsRotator at %s"), *AimAsRotator.ToString())
	auto DeltaRotator = AimAsRotator - barrelRotator;
	Barrel->Elevate(DeltaRotator.Pitch); // TODO remove magic number 
}