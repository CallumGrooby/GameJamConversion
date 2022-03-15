// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SplineManager.generated.h"

UCLASS()
class GAMEJAMCONVERSION_API ASplineManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASplineManager();

	UFUNCTION(BlueprintCallable, Category = "Events")
	bool CheckIfPuzzleIsComplete(TArray<AActor*> splineWalkers);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
