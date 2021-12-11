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
	
}

// Called every frame
void APuzzle_KeyboardInputs::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APuzzle_KeyboardInputs::InputNewKey(int characterToInput)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("INPUT KEY"));
	APuzzle_Keyboard::KeyboardLogic(characterToInput);
}

void APuzzle_KeyboardInputs::UpdateText(AActor* parentObject)
{
	
}
