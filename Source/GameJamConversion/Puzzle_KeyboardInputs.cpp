// Fill out your copyright notice in the Description page of Project Settings.


#include "Puzzle_KeyboardInputs.h"
#include "Components/BoxComponent.h"

// Sets default values
APuzzle_KeyboardInputs::APuzzle_KeyboardInputs()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APuzzle_KeyboardInputs::BeginPlay()
{
	Super::BeginPlay();

	if (monitorActor != nullptr)
	{
		monitorScript = Cast<APuzzle_Keyboard>(monitorActor);
	}

}

// Called every frame
void APuzzle_KeyboardInputs::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APuzzle_KeyboardInputs::InputNewKey(const int32 characterToInput, AActor* playerActor)
{
	//Check if the main puzzleComponent is Assigned 
	// then if true input a new code into the keyboard;

	if (monitorScript != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("Input Character"));
		monitorScript->InputNewKey(characterToInput, playerActor);
	}

	//APuzzle_Keyboard* keyboardObj = Cast<APuzzle_Keyboard>(parentObject);
	////GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, keyboardObj->GetActorLabel());
	//if (keyboardObj != nullptr)
	//{
	//	keyboardObj->KeyboardLogic(characterToInput);
	//}
}
