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


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrossair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

 void ATankPlayerController::AimTowardsCrossair()
 {
	 if (!GetControlledTank()) { return; }

	 FVector OutHitLocation;
	 if (GetSightRayHitLocation(OutHitLocation))
	 {

		//UE_LOG(LogTemp, Warning, TEXT("HitLocation %s "), *OutHitLocation.ToString());


	}
 }

 bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
 {

	 int32 ViewportSizeX, ViewportSizeY;
	 GetViewportSize(ViewportSizeX, ViewportSizeY);

	 FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	 UE_LOG(LogTemp, Warning, TEXT("Screenlocation %s "), *ScreenLocation.ToString());

	 OutHitLocation = FVector(1.f);
	 return true;

 }
