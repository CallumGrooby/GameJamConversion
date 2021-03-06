// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FuzePuzzle.generated.h"

UCLASS()
class GAMEJAMCONVERSION_API AFuzePuzzle : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AFuzePuzzle();
	UFUNCTION(BlueprintImplementableEvent, Category = "Test")
		void RunLogic();
	UFUNCTION(BlueprintImplementableEvent, Category = "Test")
		void StartPuzzle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
