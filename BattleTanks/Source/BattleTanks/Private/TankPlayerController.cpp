// #Battle Tanks is an open world TPS developed and modified by Mod_V93.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "Public/DrawDebugHelpers.h"
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
		GetControlledTank()->AimAt(OutHitLocation);
			//TODO Controlled tank should aim at this point
	}
}
//Get world location of linetrace through crosshair, true if hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const {
	//Finding the crosshair position in pixel coordinates
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto ScreenLocation = FVector2D( ViewPortSizeX * CrossHairXLocation, ViewPortSizeY * CrossHairYLocation );

	//De Projecting the screenposition to world position
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		//Line tracing to see what we'll hit
		return GetLookVectoHitLocation(LookDirection, OutHitLocation);
	}
	return false;
}
bool ATankPlayerController::GetLookVectoHitLocation(FVector LookDirection, FVector& OutHitLocation) const{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LineTraceRange * LookDirection);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
		)) 
	{
		//DrawDebugLine(GetWorld(), StartLocation, HitResult.Location, FColor(255, 0, 0), false, -1, 0, 10);
		OutHitLocation = HitResult.Location;
		return true;
	}
	return false;
}
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const{
	FVector CameraWorldLocation;// To be discarded in this use case 
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		CameraWorldLocation, 
		LookDirection);
}

