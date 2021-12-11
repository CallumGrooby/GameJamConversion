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
//Need to make is so genereated code is genrated at the start of the game.
//Currently the generated code is causing the game to crash when assigning to it, and when clicking the keyboard object in the scene

	GenerateRandomCode();
	AssignTextRenders();
}



void APuzzle_Keyboard::GenerateRandomCode()
{
	for (int32 i = 0; i <= 3; i++)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, GetActorLabel());
		generatedCode[i] = i;
		UE_LOG(LogTemp, Warning, TEXT("Int %d"), generatedCode[i]);
	}
}

void APuzzle_Keyboard::AssignTextRenders()
{
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

		UpdateMonitor(NULL, true);
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
	UpdateMonitor(currentCodePos, false);
	currentCodePos++;
	
	if (currentCodePos == generatedCode.Num())
	{
		UE_LOG(LogTemp, Warning, TEXT("Checking if code is correct"));
		if (IsCodeCorrect())
		{
			UE_LOG(LogTemp, Warning, TEXT("Puzzle Complete"));
			ShowMonitorScreen(true);
		}
		else
		{
			//Restart Puzzle;
			UE_LOG(LogTemp, Warning, TEXT("Restart Puzzle"));
			currentCodePos = 0;
			ShowMonitorScreen(false);
			UpdateMonitor(NULL, true);
		}
	}
}
void APuzzle_Keyboard::ShowMonitorScreen(bool codeOutcome)
{
	UTextRenderComponent* outputText = Cast<UTextRenderComponent>(monitor->GetDefaultSubobjectByName(TEXT("txtError")));

	if (outputText != nullptr)
	{
		outputText->SetVisibility(true);
//Wait for X seconds
		//FTimerHandle TimerHandle;
		//GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&](){
		//	outputText->SetVisibility(false);
		//}, 3, false);



		if (codeOutcome)
		{
			//Puzzle Complete
			outputText->SetText(TEXT("Correct"));
		}
		else
		{
			outputText->SetText(TEXT("Incorrect"));
		}
	}

}


bool APuzzle_Keyboard::IsCodeCorrect()
{
	for (size_t i = 0; i < 3; i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("Inputed Code %d   %d"), inputedCode[i], generatedCode[i]);
		if (inputedCode[i] != generatedCode[i])
		{
			//return false;
		}
	}
	return true;
}



void APuzzle_Keyboard::UpdateMonitor(int currentCharacterIndex, bool doOnce)
{
	if (doOnce)
	{
		text[0]->SetText(TEXT("_"));
		text[1]->SetText(TEXT("_"));
		text[2]->SetText(TEXT("_"));
		text[3]->SetText(TEXT("_"));
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (currentCharacterIndex == i)
		{
			UE_LOG(LogTemp, Warning, TEXT("currentCharacter %d"), i);
			text[i]->SetText(TEXT("*"));
		}
	}
}


