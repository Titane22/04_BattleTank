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
	//-1 is minmum speed and 1 is maximum speed
	void Elevate(float RelativeSpeed);
	//bool GetRotatable(FVector DeltaRotator);
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSeconds = 10.f;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesElevation = 40.f;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinDegreesElevation = 0.f;
};
