// Fill out your copyright notice in the Description page of Project Settings.

#include "SplineManager.h"
#include "StaticObjects.h"
//#include "SplineWalker.h"


// Sets default values
ASplineManager::ASplineManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

bool ASplineManager::CheckIfPuzzleIsComplete()
{
	for (size_t i = 0; i < splineWalkers.Num(); i++)
	{
		ASplineWalker* spline = Cast<ASplineWalker>(splineWalkers[i]);
		if (spline != nullptr)
		{
			if (spline->isFinished == false)
			{
				return false;
			}
		}
	}
	return true;
}

void ASplineManager::UnlockDoor()
{
	for (size_t i = 0; i < puzzleToUnlock.Num(); i++)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("Open Door Called"));
		if (puzzleToUnlock[i] == nullptr)
			return;

		AStaticObjects* puzzleToTrigger = Cast<AStaticObjects>(puzzleToUnlock[i]);
		if (puzzleToTrigger != nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("Open Door"));
			puzzleToTrigger->UnlockObject();
		}
	}
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

