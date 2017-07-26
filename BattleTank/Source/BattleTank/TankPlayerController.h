// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
private:
	ATank* GetControlledTank() const;
	
	// Start the tank moving the barrel so that a shot would hit where
	// the crosshair interects the world
	void AimTowardsCrosshair();
	bool GetSightRayLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditAnyWhere)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnyWhere)
	float CrossHairYLocation = 0.3333f;

	UPROPERTY(EditAnyWhere)
	float LineTraceRange = 1000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
	

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
