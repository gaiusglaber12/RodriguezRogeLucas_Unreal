// Fill out your copyright notice in the Description page of Project Settings.


#include "APaddle.h"

#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AAPaddle::AAPaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Paddle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM Paddle"));
	RootComponent = SM_Paddle;

	SM_Paddle->SetEnableGravity(false);
	SM_Paddle->SetConstraintMode(EDOFMode::XZPlane);
	//SM_Paddle->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Paddle->SetCollisionProfileName(TEXT("PhysicsActor"));

	floatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating movement"));
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

}

// Called to bind functionality to input
void AAPaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAPaddle::MoveHorizontal(float speedValue)
{
	AddMovementInput(FVector(speedValue, 0.0f, 0.0f), 1.0f, false);
}

