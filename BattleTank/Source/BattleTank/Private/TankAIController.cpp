// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "BattleTank.h"


void ATankAIController::BeginPlay() 
{
    Super::BeginPlay();

    auto PlayerTank = GetPlayerTank();
    if (!PlayerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank!"));
    } 
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));
    }
}


ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank> ( GetPawn() );
}

ATank* ATankAIController::GetPlayerTank() const
{
    
    auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (!PlayerPawn)
    {
        return nullptr;
    } 
    else
    {
        return Cast<ATank>(PlayerPawn);
        //UE_LOG(LogTemp, Warning, TEXT(""), *(ControlledTank->GetName()));
    }
}


// Called every frame ///I Added
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    if(GetPlayerTank())
    {
        //TODO Move Towards player

        //Aim towards player
        GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

        //Fire if ready
    }
}