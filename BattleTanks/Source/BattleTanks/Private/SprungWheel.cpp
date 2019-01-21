// #Battle Tanks is an open world TPS developed and modified by Mod_V93

#include "SprungWheel.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include "Engine/Classes/PhysicsEngine/PhysicsConstraintComponent.h"
#include "Engine/Classes/Components/SphereComponent.h"

// Sets default values
ASprungWheel::ASprungWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TankAxle = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Tank Axle Constraint"));
	SetRootComponent(TankAxle);

	Axle = CreateDefaultSubobject<USphereComponent>(FName("Axle"));
	Axle->SetupAttachment(TankAxle);

	AxleWheelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Axle Wheel Constraint"));
	AxleWheelConstraint->SetupAttachment(Axle);

	Wheel = CreateDefaultSubobject<USphereComponent>(FName("Wheel"));
	Wheel->SetupAttachment(Axle); //AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	
}

// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();
	SetupConstraint();
}
void ASprungWheel::SetupConstraint()
{

	if (!GetAttachParentActor()) { return; }
	UPrimitiveComponent *BodyRoot = Cast<UPrimitiveComponent>(GetAttachParentActor()->GetRootComponent());
	if (!BodyRoot) { return; }

	auto AxlePhysicsContraintComponent = Cast<UPrimitiveComponent>(Axle);
	auto WheelPhysicsContraintComponent = Cast<UPrimitiveComponent>(Wheel);

	TankAxle->SetConstrainedComponents(BodyRoot, NAME_None, AxlePhysicsContraintComponent, NAME_None);
	AxleWheelConstraint->SetConstrainedComponents(AxlePhysicsContraintComponent, NAME_None, WheelPhysicsContraintComponent, NAME_None);
}
// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

