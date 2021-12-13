// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/TextRenderComponent.h"
#include "Containers/Array.h"
#include "Puzzle_Keyboard.h"
#include "Puzzle_KeyboardInputs.h"
#include <GameJamConversion/FuzePuzzle.h>
#include <string> 

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
		//AssignInputs();
	GenerateRandomCode();
	AssignTextRenders();
}

void APuzzle_Keyboard::AssignInputs()
{
	//Doesnt work | Done in blue print now
		////Get All child components
		//AActor* inputtedCharacters[] = {
		//Cast<AActor>(this->GetOwner()->GetDefaultSubobjectByName(TEXT("KeyboardInput1"))),
		//Cast<AActor>(this->GetOwner()->GetDefaultSubobjectByName(TEXT("KeyboardInput2"))),
		//Cast<AActor>(this->GetOwner()->GetDefaultSubobjectByName(TEXT("KeyboardInput3"))),
		//Cast<AActor>(this->GetOwner()->GetDefaultSubobjectByName(TEXT("KeyboardInput4"))),
		//};

		////UE_LOG(LogTemp, Warning, TEXT("This a testing statement. %s"), this->GetOwner()->GetActorLabel());


		//for (size_t i = 0; i < 3; i++)
		//{
		//	if (inputtedCharacters[i] != nullptr)
		//	{
		//		APuzzle_KeyboardInputs* tmp = Cast<APuzzle_KeyboardInputs>(inputtedCharacters[i]);
		//		if (tmp != nullptr)
		//		{
		//			UE_LOG(LogTemp, Warning, TEXT("Casted to input"));
		//			tmp->inputCharacter = i;
		//			tmp->LateStart();
		//		}
		//		else
		//		{
		//			UE_LOG(LogTemp, Warning, TEXT("failed to cast to input"));
		//		}
		//	}
		//	else
		//	{
		//		UE_LOG(LogTemp, Warning, TEXT("failed to cast to actor"));
		//	}
		//	//inputtedCharacters[i]->inputCharacter = i;
		//	//inputtedCharacters[i]->LateStart();
		//}
}

void APuzzle_Keyboard::GenerateRandomCode()
{
	for (int32 i = 0; i <= 3; i++)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, GetActorLabel());
		generatedCode[i] = FMath::RandRange(0, 3);
		UE_LOG(LogTemp, Warning, TEXT("Int %d"), generatedCode[i]);
	}

	//Display Code on note

	if (stickyNote != nullptr)
	{
		UTextRenderComponent* stickyNoteCode = Cast<UTextRenderComponent>(stickyNote->GetDefaultSubobjectByName(TEXT("txtCode")));
		if (stickyNoteCode != nullptr)
		{
			FString IntAsString = FString::FromInt(generatedCode[0]);
			FString IntAsString1 = FString::FromInt(generatedCode[1]);
			FString IntAsString2 = FString::FromInt(generatedCode[2]);
			FString IntAsString3 = FString::FromInt(generatedCode[3]);
			stickyNoteCode->SetText(IntAsString + " " + IntAsString1 + " " + IntAsString2 + " " + IntAsString3);

		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("failed to cast to Textrender"));
		}

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
	if (puzzleIsComplete)
	{
		return;
	}
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
			puzzleIsComplete = true;

			if (fuzePuzzle != nullptr)
			{
				AFuzePuzzle* tmp = Cast<AFuzePuzzle>(fuzePuzzle);
				if (tmp != nullptr)
				{
					tmp->StartPuzzle();
				}
			}

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
		if (codeOutcome)
		{
			//Puzzle Complete
			outputText->SetText(TEXT("Correct"));
		}
		else
		{
			outputText->SetText(TEXT("Incorrect"));
		}

		HideText(outputText);
	}

}


bool APuzzle_Keyboard::IsCodeCorrect()
{
	for (size_t i = 0; i < 3; i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("Inputed Code %d   %d"), inputedCode[i], generatedCode[i]);
		if (inputedCode[i] != generatedCode[i])
		{
			return false;
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


