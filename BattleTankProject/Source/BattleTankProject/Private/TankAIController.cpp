// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	//UE_LOG(LogTemp, Warning, TEXT("AI Controller Begin Play"));

	ATank* ControlledTank = GetControlledTank();
	if (ControlledTank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank: %s"), *ControlledTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AI is not possessing a Tank!"));
	}

	ATank* PlayerTank = GetPlayerTank();
	if (PlayerTank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s will chase %s"), *ControlledTank->GetName(), *PlayerTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Player Tank was found!"));
	}

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PlayerTank)
	{
		return Cast<ATank>(PlayerTank);
	}
	else
	{
		return nullptr;
	}

}