// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Member Variables
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement") bool bMovingForward = true;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement") FVector StartLocation = FVector(0.0f, 0.0f, 0.0f);
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement") FVector EndLocation = FVector(0.0f, 0.0f, 0.0f);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement") float TravelDistance = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement") float MoveDistance = 0.0f;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement") FVector PlatformVelocity = FVector(0.0f, 0.0f, 0.0f);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement") FRotator PlatformRotationRate = FRotator(0.0f, 0.0f, 0.0f);
	

	// Member Functions
	UFUNCTION(BlueprintCallable, Category = "Movement") void MovePlatform(float DeltaTime);
	UFUNCTION(BlueprintCallable, Category = "Movement") void RotatePlatform(float DeltaTime);
	UFUNCTION(BlueprintCallable, Category = "Movement") void InvertPlatformDirection(FVector NewStartLocation); 
	UFUNCTION(BlueprintCallable, Category = "Movement") FVector GetEndPoint(); 
};
