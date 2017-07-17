// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

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
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
