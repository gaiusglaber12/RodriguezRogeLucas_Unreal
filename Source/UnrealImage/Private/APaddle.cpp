// Fill out your copyright notice in the Description page of Project Settings.


#include "APaddle.h"
#include <sstream>

#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"

// Sets default values
AAPaddle::AAPaddle()
{
 	
}

// Called when the game starts or when spawned
void AAPaddle::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AAPaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector newLocation = GetActorLocation();
	if (newLocation.X <= leftCondition && newLocation.X >= rightCondition) {
		newLocation.X = GetActorLocation().X + (movementDirection.X * movementSpeed * DeltaTime);
		SetActorLocation(newLocation);
	}
	else if (newLocation.X <= leftCondition)
	{
		newLocation.X = leftCondition;
		SetActorLocation(newLocation);
	}
	else
	{
		newLocation.X = rightCondition;
		SetActorLocation(newLocation);
	}
}

// Called to bind functionality to input
void AAPaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveHorizontal", this, &AAPaddle::MoveHorizontal);

}

void AAPaddle::MoveHorizontal(float Value)
{
	movementDirection.X = FMath::Clamp(Value, -1.0f, 1.0f);
}

