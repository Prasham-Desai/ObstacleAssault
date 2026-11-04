// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	// Storing Start Location and End Location of the platform to use it later in MovePlatform function
	StartLocation = GetActorLocation();
	EndLocation = GetEndPoint();
	bMovingForward = true;
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);

}


// These are member functions and can access the UE5 engine features like UE_LOG, UPROPERTY, etc. They are part of the AMovingPlatform class.
// Can be written anywhere and still be accessed in BeginPlay and Tick.
void AMovingPlatform::MovePlatform(float DeltaTime)
{
	// Move Platform based on the PlatfromVelocity.

	FVector CurrentLocation = GetActorLocation();
	CurrentLocation += (PlatformVelocity * DeltaTime);
	SetActorLocation(CurrentLocation);

	/* Checking if the platform has reached the end location or start location based on the direction 
	of movement and inverting the direction if it has reached the target location.*/

	FVector TargetLocation = bMovingForward ? EndLocation : StartLocation;
	FVector MoveDirection = PlatformVelocity.GetSafeNormal();
	float DistanceBeyondTarget = FVector::DotProduct((CurrentLocation - TargetLocation), MoveDirection);
	
	if (DistanceBeyondTarget > 0.0f)
	{
		SetActorLocation(TargetLocation);
		InvertPlatformDirection(TargetLocation);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	FRotator RotationToAdd = (PlatformRotationRate * DeltaTime);
	AddActorLocalRotation(RotationToAdd);
}

FVector AMovingPlatform::GetEndPoint()
{
	EndLocation = StartLocation + (PlatformVelocity.GetSafeNormal() * MoveDistance);

	return EndLocation;
}

void AMovingPlatform::InvertPlatformDirection(FVector NewStartLocation)
{
	// Setting Correct Location of the platform to avoid overshooting and Inverting the direction of the platform
	UE_LOG(LogTemp, Display, TEXT("Start Location: %s"), *StartLocation.ToString());
	UE_LOG(LogTemp, Display, TEXT("End Location: %s"), *EndLocation.ToString());
	bMovingForward = !bMovingForward;
	PlatformVelocity = -PlatformVelocity;
}
