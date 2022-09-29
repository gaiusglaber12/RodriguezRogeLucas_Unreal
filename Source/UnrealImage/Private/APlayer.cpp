// Fill out your copyright notice in the Description page of Project Settings.


#include "APlayer.h"

// Sets default values
AAPlayer::AAPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!movementDirection.IsZero()) {
		const FVector newLocation = GetActorLocation() + (movementDirection * DeltaTime + movementSpeed);
		SetActorLocation(newLocation);
	}
}

// Called to bind functionality to input
void AAPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveHorizontal", this, &AAPlayer::MoveHorizontal);
}

void AAPlayer::MoveHorizontal(float Value)
{
	
	movementDirection.X = FMath::Clamp(Value, -1.0f, 1.0f);
}