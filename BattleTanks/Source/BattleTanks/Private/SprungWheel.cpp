// #Battle Tanks is an open world TPS developed and modified by Mod_V93

#include "SprungWheel.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include "Engine/Classes/PhysicsEngine/PhysicsConstraintComponent.h"

// Sets default values
ASprungWheel::ASprungWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mass = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mass"));
	SetRootComponent(Mass);

	Wheel = CreateDefaultSubobject<UStaticMeshComponent>(FName("Wheel"));
	Wheel->SetupAttachment(Mass); //AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	MassWheelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Mass Wheel Constraint"));
	MassWheelConstraint->SetupAttachment(Mass);
}

// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

