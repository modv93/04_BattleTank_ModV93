// #Battle Tanks is an open world TPS developed and modified by Mod_V93

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if(ensure(PlayerTank))
	{
		//Move towards the player 
		MoveToActor(PlayerTank, AcceptanceRadius);

		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire();
	}
	//UE_LOG(LogTemp, Warning, "%s AI is aiming at %s player", *GetControlledTank->GetName(), *AimAt(GetPlayerTank()->GetActorLocation()))
}




