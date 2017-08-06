// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable,Category = Input)
	void SetThrotlle(float Throttle);
	
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 400000; // Assume 40 tonne tank, and 1g acceleration 

	
};
