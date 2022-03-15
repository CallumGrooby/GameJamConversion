// Fill out your copyright notice in the Description page of Project Settings.


#include "SplineManager.h"

// Sets default values
ASplineManager::ASplineManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

bool ASplineManager::CheckIfPuzzleIsComplete(TArray<AActor*> splineWalkers)
{
	for (size_t i = 0; i < splineWalkers.Num(); i++)
	{
		if (true)
		{

		}
	}

	return false;
}

// Called when the game starts or when spawned
void ASplineManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASplineManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

