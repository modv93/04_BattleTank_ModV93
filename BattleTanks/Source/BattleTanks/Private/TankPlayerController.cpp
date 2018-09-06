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
void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("Player Controller Tick"))
	AimTowardsCrossHair();
}
ATank * ATankPlayerController::GetControlledTank() const
{	
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank()) {	return;	}
	FVector OutHitLocation; // Out Parameter
	if (GetSightRayHitLocation(OutHitLocation)) {
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation is %s"), *OutHitLocation.ToString())
			//TODO Controlled tank should aim at this point
	}
}
//Get world location of linetrace through crosshair, true if hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const {
	//Finding the crosshair position in pixel coordinates
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto ScreenLocation = FVector2D( ViewPortSizeX * CrossHairXLocation, ViewPortSizeY * CrossHairYLocation );
	//UE_LOG(LogTemp, Warning, TEXT("ScreenLocation is %s"), *ScreenLocation.ToString())
	//De Projectng the screenposition to worl position
	FVector CameraWorldLocation, WorldDirection;
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, WorldDirection)) {
		UE_LOG(LogTemp, Warning, TEXT("World Direction is %s"), *WorldDirection.ToString())
	}
	OutHitLocation = FVector(1.0f);
	return true;
}
