// #Battle Tanks is an open world TPS developed and modified by Mod_V93

#include "SprungWheel.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include "Engine/Classes/PhysicsEngine/PhysicsConstraintComponent.h"

// Sets default values
ASprungWheel::ASprungWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MassWheelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Mass Wheel Constraint"));
	SetRootComponent(MassWheelConstraint);
	
	Wheel = CreateDefaultSubobject<UStaticMeshComponent>(FName("Wheel"));
	Wheel->SetupAttachment(MassWheelConstraint); //AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	
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

	auto WheelPhysicsContraintComponent = Cast<UPrimitiveComponent>(Wheel);
	MassWheelConstraint->SetConstrainedComponents
	(
		BodyRoot,
		NAME_None,
		WheelPhysicsContraintComponent,
		NAME_None
	);
}
// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

