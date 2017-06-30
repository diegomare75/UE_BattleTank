// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController MSG: AI Controlled Tank not found!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController MSG: AI Controlled Tank = %s"), *(ControlledTank->GetName()));
	}

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController MSG: Player Controlled Tank not found!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController MSG: Player Controlled Tank = %s"), *(PlayerTank->GetName()));
		UE_LOG(LogTemp, Warning, TEXT("TankAIController MSG: Player Controlled Tank = %s"), *(PlayerTank->GetActorLocation().ToString()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (GetPlayerTank())
	{
		// move towards the player

		// aim the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// fire when ready
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if(!PlayerPawn)	{ return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
