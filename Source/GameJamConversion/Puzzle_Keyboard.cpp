// Fill out your copyright notice in the Description page of Project Settings.


#include "Puzzle_Keyboard.h"

// Sets default values
APuzzle_Keyboard::APuzzle_Keyboard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

int generatedCode[4]{ 1,2,3,4 };
int currentCodePos = 0;
int inputedCode[4]{0,0,0,0};
// Called when the game starts or when spawned
void APuzzle_Keyboard::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APuzzle_Keyboard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APuzzle_Keyboard::KeyboardLogic(int inputedDigit)
{
	inputedCode[currentCodePos] = inputedDigit;
	
	FString debugmessage = FString::Printf(TEXT("Text, %d"), inputedCode[currentCodePos]);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, debugmessage);
	currentCodePos++;


	if (currentCodePos > sizeof(generatedCode))
	{
		if (IsCodeCorrect())
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("PuzzleComplete"));
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("Restart Puzzle"));
			for (int i = 0; i < sizeof(generatedCode); i++)
			{
				inputedCode[i] = 0;
			}
			currentCodePos = 0;
		}
		
		//Puzzle Complete
		return;
	}
}

bool APuzzle_Keyboard::IsCodeCorrect()
{
	for (size_t i = 0; i < sizeof(generatedCode); i++)
	{
		if (inputedCode[i] != generatedCode[i])
		{
			return false;
		}
	}

	return true;
}


