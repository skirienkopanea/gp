// GNU GENERAL PUBLIC LICENSE

#include "Door.h"
#include "Engine/World.h"
#include "Components/AudioComponent.h"

ADoor::ADoor()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
	//AudioComponent = GetOwner()->FindComponentByClass<UAudioComponent>();
	Rotation = GetActorRotation();
	InitialYaw = Rotation.Yaw;
};

void ADoor::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	int Mass = (int) GetTotalMass();

	if (Mass > 15)
	{
		Open();
	}
	else
	{
		Close();
	}
	
}

void ADoor::Open()
{
	//if ((int)Rotation.Yaw % 380 == InitialYaw) {
		//AudioComponent->Play();
	//}

	Rotation.Yaw = FMath::Lerp(Rotation.Yaw, TargetYaw, 0.1);
	SetActorRotation(Rotation);
	//UE_LOG(LogTemp, Warning, TEXT("Open"));

}

void ADoor::Close()
{

	Rotation.Yaw = FMath::Lerp(Rotation.Yaw, InitialYaw, 0.1);
	SetActorRotation(Rotation);

	if (FMath::Abs((int)Rotation.Yaw % 380 - InitialYaw) < 10 && FMath::Abs((int)Rotation.Yaw % 380 - InitialYaw) > 5) {
		//AudioComponent->Play();
	}

	//UE_LOG(LogTemp, Warning, TEXT("Close"));

}

float ADoor::GetTotalMass() {

	float TotalMass = 0.0f;

	TArray<AActor*> OverlappingActors;
	PressurePlate->GetOverlappingActors(OverlappingActors);

	for (AActor* Actor : OverlappingActors) {
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		//UE_LOG(LogTemp, Warning, TEXT("%s is on the pressure plate!"), *Actor->GetName());
	}

	//UE_LOG(LogTemp, Warning, TEXT("%d mass on the pressure plate!"), TotalMass);


	return TotalMass;
}