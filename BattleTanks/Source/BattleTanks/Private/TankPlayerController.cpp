// #Battle Tanks is an open world TPS developed and modified by Mod_V93.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play"))
		auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Player Controller not possessing a tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller is possessing %s"), *(ControlledTank->GetName()))
	}
}
ATank * ATankPlayerController::GetControlledTank() const
{	
	return Cast<ATank>(GetPawn());
}

