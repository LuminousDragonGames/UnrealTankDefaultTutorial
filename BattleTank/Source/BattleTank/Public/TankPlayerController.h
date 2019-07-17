// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
//Must be last include
#include "TankPlayerController.generated.h"


class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override; //(inherit BeginPlay for AActor -  its virtual)

	virtual void Tick(float DeltaTime) override;

private: 
	ATank* GetControlledTank() const;

	//start tank moving barrel so that a shot would hit
	// where the crosshair intersects the world.
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation) const; ///Out removed

	UPROPERTY (EditDefaultsOnly) 
	float CrosshairXLocation = 0.5;

    UPROPERTY (EditDefaultsOnly) 
	float CrosshairYLocation = 0.33333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 500000; //i altered this to half.

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
