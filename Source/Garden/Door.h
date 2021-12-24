// GNU GENERAL PUBLIC LICENSE

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/TriggerVolume.h"
#include "Door.generated.h"

/**
 *
 */
UCLASS()
class GARDEN_API ADoor : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	ADoor();
	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//void OpenDoor(float DeltaTime);
	//void CloseDoor(float DeltaTime);
	void FindAudioComponent();

private:
	FRotator Rotation;
	float InitialYaw;
	float LastOpen; 

	UPROPERTY(EditAnywhere)
	float TargetYaw;

	UPROPERTY(EditAnywhere)
	float DoorSpeed;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate;

	UPROPERTY()
	UAudioComponent* AudioComponent = nullptr;

	void Open(float DeltaTime);
	void Close(float DeltaTime);;
	float GetTotalMass();
};