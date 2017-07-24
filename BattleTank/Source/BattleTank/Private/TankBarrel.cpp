// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float DegreePerSecond)
{
	// move	the barrel the right amount this frame
	// Given a max elevation speed ,and the frame time
	UE_LOG(Logtemp,Warning,TEXT("Barrel Elevate : %f"),DegreePerSecond)
}

