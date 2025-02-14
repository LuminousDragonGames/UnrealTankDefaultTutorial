// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "BattleTank.h"


void ATankAIController::BeginPlay() 
{
    Super::BeginPlay();
}

// Called every frame ///I Added
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
    {
        //TODO Move Towards player

        //Aim towards player
        ControlledTank->AimAt(PlayerTank->GetActorLocation());

        ControlledTank->Fire(); // TODO limit firing rate
    }
}