// Fill out your copyright notice in the Description page of Project Settings.


#include "AABrickSpawner.h"
#include "Engine/World.h"

// Sets default values
AAABrickSpawner::AAABrickSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AAABrickSpawner::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	FRotator Rotation = GetActorRotation();
	FActorSpawnParameters SpawnInfo;
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("Your Message"));
	for (int i = 0; i < cantY; i++)
	{
		for (int j = 0; j < cantX; j++)
		{
			FVector brickPosition = GetActorLocation();
			brickPosition.X += offsetX;
			brickPosition.Z += offsetY;
			World->SpawnActor(BPBrick->StaticClass(), &brickPosition, &Rotation);
		}
	}
	
}

void AAABrickSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

