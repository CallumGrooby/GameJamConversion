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

TArray<int32> inputedCode;


int currentCodePos = 0;
// Called when the game starts or when spawned
void APuzzle_Keyboard::BeginPlay()
{
	Super::BeginPlay();

	generatedCode.Init(1, 3);
	UE_LOG(LogTemp, Warning, TEXT("array %d"), generatedCode.Num());

	for (int32 i = 0; i <= generatedCode.Num(); i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("num %d"), i);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, GetActorLabel());
		//generatedCode[i] = i
	}

	if (monitor != NULL)
	{
		UTextRenderComponent* editableText[] = { Cast<UTextRenderComponent>(monitor->GetDefaultSubobjectByName(TEXT("InputChar1"))), 
			Cast<UTextRenderComponent>(monitor->GetDefaultSubobjectByName(TEXT("InputChar2"))),
			Cast<UTextRenderComponent>(monitor->GetDefaultSubobjectByName(TEXT("InputChar3"))),
			Cast<UTextRenderComponent>(monitor->GetDefaultSubobjectByName(TEXT("InputChar4"))),
		};
		
		for (size_t i = 0; i < 4; i++)
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
	//UpdateMonitor(NULL);
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
				//inputedCode[i] = 0;
			}
			currentCodePos = 0;
		}
		
		//Puzzle Complete
		return;
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
	if (currentCharacterIndex == NULL)
	{
		for (int i = 0; i < generatedCode.Num(); i++)
		{
			FString debugmessage = FString::Printf(TEXT("Text, %d"), i);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, debugmessage);
		}

		text[0]->SetText(TEXT("Text"));
		text[1]->SetText(TEXT("Text"));
		text[2]->SetText(TEXT("Text"));
		text[3]->SetText(TEXT("Text"));
		return;
	}
}


