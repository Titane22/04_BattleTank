// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	void Elevate(float DegreesPerSecond);
	//bool GetRotatable(FVector DeltaRotator);
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreePerSpeed = 20.f;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevation = 40.f;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevation = 0.f;
};
