// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AABrickSpawner.generated.h"

UCLASS()
class UNREALIMAGE_API AAABrickSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAABrickSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"));
	TSubclassOf<AActor> BPBrick;

	UPROPERTY(EditAnywhere, Category = "BPRefferences");
	int cantX;
	UPROPERTY(EditAnywhere, Category = "BPRefferences");
	int cantY;

	UPROPERTY(EditAnywhere, Category = "BPRefferences");
	int offsetX;

	UPROPERTY(EditAnywhere, Category = "BPRefferences");
	int offsetY;
};
