// #Battle Tanks is an open world TPS developed and modified by Mod_V93

#include "TankTrack.h"


UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpulse, const FHitResult & Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("On hit called "));
}

void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	//Good practice to use this, however doesn't make any dfference here.
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction); 

	//Calculate slippage speed
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());

	//Work-out required accelartion this frame to correct, measured in the opposite direction, hence the negative
	auto CorrectionAccelaration = - ( SlippageSpeed / DeltaTime * GetRightVector() );

	//Calculate and apply for sideways (F = M  * a)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = ( TankRoot->GetMass() * CorrectionAccelaration ) / 2;
	TankRoot->AddForce(CorrectionForce);

}
void UTankTrack::SetThrottle(float Throttle)
{

	//TODO clamp actual throttle value so player can't over-drive
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

}
