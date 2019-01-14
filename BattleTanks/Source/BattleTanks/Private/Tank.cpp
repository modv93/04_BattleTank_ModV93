// #Battle Tanks is an open world TPS developed and modified by Mod_V93

#include "Tank.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{
	auto DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	auto DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);

	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0)
	{
		OnDeath.Broadcast();
	}
	
	return DamageToApply;
}

float ATank::GetHealthPercentage() const
{
	return ( (float)CurrentHealth / (float)StartingHealth );
}


