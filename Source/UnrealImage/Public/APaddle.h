// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "APaddle.generated.h"

class UFloatingPawnMovement;

UCLASS()
class UNREALIMAGE_API AAPaddle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAPaddle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	FVector movementDirection;
	UPROPERTY(EditAnywhere, Category = "Movement");
	float movementSpeed = 500.0f;

	void MoveHorizontal(float Value);

};
