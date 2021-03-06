// Copyright EmbracedIT Ltd

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankPlayerController.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetPawn()) { return; }
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	
	FVector HitLocation; //Out Parmeter
	bool bGotHitLocation = GetSightRayLocation(HitLocation);
	
	if (bGotHitLocation) //Has "side-effect", is going to line trace
	{
		AimingComponent->AimAt(HitLocation);
		//TODO Tell controlled tank to aim at this point
	}
}

//Get world location of linetrace through crosshair if it hits the landscape,then get location.
bool ATankPlayerController::GetSightRayLocation(FVector& HitLocation) const
{
	// Find the crosshair position in pixel coordinates
	int32 ViewportX, ViewportY;

	GetViewportSize(ViewportX, ViewportY);
	auto ScreenLocation = FVector2D(CrossHairXLocation*ViewportX, CrossHairYLocation*ViewportY);

	
	FVector LookDirection;
	
	// "De-project" the screen position of the crosshair to a world direction
	if (GetLookDirection(ScreenLocation,LookDirection))
	{
		// Line-trace along that LookDirection, and see what we hit ( up to max range)
		return GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	
	return false;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection*LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
			OUT HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
		)
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;

	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
}

