// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SplineWalker.h"
#include "StaticObjects.h"
#include "SplineManager.generated.h"

UCLASS()
class GAMEJAMCONVERSION_API ASplineManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASplineManager();
	UFUNCTION(BlueprintCallable, Category = "Events")
	bool CheckIfPuzzleIsComplete();

	UFUNCTION(BlueprintCallable, Category = "Events")
		void UnlockDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Editable Variables")
	TArray<AActor*> splineWalkers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unasigned Actors")
	AActor* puzzleToUnlock;



};
