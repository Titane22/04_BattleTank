// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}
// but, Ai don't have Deproject
// Call AimAt from GetControlledTank()

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto ControlledTank = Cast<ATank>(GetPawn());
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PlayerTank)
	{
		// TODO Move towards the player
		
		// Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// Fire if ready
		ControlledTank->Fire();
	}
}
