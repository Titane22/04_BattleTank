// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"

void UTankTurret::Turning(float RelativeSpeed) {
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto TurningChange = RelativeSpeed * MaxDegreesPerSeconds*GetWorld()->DeltaTimeSeconds;
	auto RawNewTurning = RelativeRotation.Roll + TurningChange;
	auto Turning = FMath::Clamp<float>(RawNewTurning, 0, 360);
	SetRelativeRotation(FRotator(0, 0, Turning));
}


