// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/TextRenderComponent.h"
#include "Containers/Array.h"
#include "Puzzle_Keyboard.h"

// Sets default values
APuzzle_Keyboard::APuzzle_Keyboard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}
// Called when the game starts or when spawned
void APuzzle_Keyboard::BeginPlay()
{
	Super::BeginPlay();
	currentCodePos = 0;
	generatedCode.Init(1, 4);
	for (int32 i = 0; i <= 4; i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("num %d"), i);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, GetActorLabel());
		//generatedCode[i] = i
	}

	if (monitor != NULL)
	{
		UTextRenderComponent* editableText[] = { 
			Cast<UTextRenderComponent>(monitor->GetDefaultSubobjectByName(TEXT("InputChar1"))), 
			Cast<UTextRenderComponent>(monitor->GetDefaultSubobjectByName(TEXT("InputChar2"))),
			Cast<UTextRenderComponent>(monitor->GetDefaultSubobjectByName(TEXT("InputChar3"))),
			Cast<UTextRenderComponent>(monitor->GetDefaultSubobjectByName(TEXT("InputChar4"))),
		};
			for (size_t i = 0; i <= generatedCode.Num(); i++)
			{
				text.Add(editableText[i]);
			}
			UpdateMonitor(NULL);
	}
}

// Called every frame
void APuzzle_Keyboard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APuzzle_Keyboard::KeyboardLogic(int32 inputedDigit)
{
	inputedCode[currentCodePos] = inputedDigit;
	UpdateMonitor(currentCodePos);
	UE_LOG(LogTemp, Warning, TEXT("currentCodePos %d"), currentCodePos);
	currentCodePos++;
	UE_LOG(LogTemp, Warning, TEXT("generatedCode %d"), generatedCode.Num());
	if (currentCodePos == generatedCode.Num()+1)
	{
		currentCodePos = 0;
	}
}

bool APuzzle_Keyboard::IsCodeCorrect()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (inputedCode[i] != generatedCode[i])
		{
			return false;
		}
	}

	return true;
}

void APuzzle_Keyboard::UpdateMonitor(int currentCharacterIndex)
{
	for (size_t i = 0; i < text.Num(); i++)
	{
		if (currentCharacterIndex != NULL && currentCharacterIndex == i)
		{
			text[i]->SetText(TEXT("*"));
		}
		else 
		{
			text[i]->SetText(TEXT("_"));
		}
	}
}


