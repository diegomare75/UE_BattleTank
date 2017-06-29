// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController MSG: Player Controlled Tank not found!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController MSG: Player Controlled Tank = %s"), *(ControlledTank->GetName()));
	}	
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

