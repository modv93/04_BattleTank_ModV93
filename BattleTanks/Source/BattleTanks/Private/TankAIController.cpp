// #Battle Tanks is an open world TPS developed and modified by Mod_V93

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	/*if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller not possessing a tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller is possessing %s"), *(ControlledTank->GetName()))
	}*/
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller couldn't find the player"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller found %s"), *(PlayerTank->GetName()))
	}
}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(GetPlayerTank())
	{
		//TODO move towards the player 

		//Aim at the player 
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		//Fire if ready
	}
	//UE_LOG(LogTemp, Warning, "%s AI is aiming at %s player", *GetControlledTank->GetName(), *AimAt(GetPlayerTank()->GetActorLocation()))
}
ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
ATank* ATankAIController::GetPlayerTank() const {
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


