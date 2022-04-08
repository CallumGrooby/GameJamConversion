// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SplineWalker.generated.h"

UCLASS()
class GAMEJAMCONVERSION_API ASplineWalker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASplineWalker();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Editable Variables")
		bool isFinished;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
