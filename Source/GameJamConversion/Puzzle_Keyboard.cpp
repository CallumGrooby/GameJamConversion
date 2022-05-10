// Fill out your copyright notice in the Description page of Project Settings.

#include "Puzzle_Keyboard.h"
#include "Components/TextRenderComponent.h"
#include "Containers/Array.h"
#include "Puzzle_KeyboardInputs.h"
#include "ThirdPersonCharacter.h"
#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"
#include "StaticObjects.h"
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
	GenerateRandomCode();
	////Need to make is so genereated code is genrated at the start of the game.
	////Currently the generated code is causing the game to crash when assigning to it, and when clicking the keyboard object in the scene
	//	//AssignInputs();
	//GenerateRandomCode();
	//AssignTextRenders();
}

void APuzzle_Keyboard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("Generated Code Is %d %d %d %d"), generatedCode[0], generatedCode[1], generatedCode[2], generatedCode[3]);
}

//void APuzzle_Keyboard::AssignInputs()
//{
//	//Doesnt work | Done in blue print now
//		////Get All child components
//		//AActor* inputtedCharacters[] = {
//		//Cast<AActor>(this->GetOwner()->GetDefaultSubobjectByName(TEXT("KeyboardInput1"))),
//		//Cast<AActor>(this->GetOwner()->GetDefaultSubobjectByName(TEXT("KeyboardInput2"))),
//		//Cast<AActor>(this->GetOwner()->GetDefaultSubobjectByName(TEXT("KeyboardInput3"))),
//		//Cast<AActor>(this->GetOwner()->GetDefaultSubobjectByName(TEXT("KeyboardInput4"))),
//		//};
//
//		////UE_LOG(LogTemp, Warning, TEXT("This a testing statement. %s"), this->GetOwner()->GetActorLabel());
//
//		//for (size_t i = 0; i < 3; i++)
//		//{
//		//	if (inputtedCharacters[i] != nullptr)
//		//	{
//		//		APuzzle_KeyboardInputs* tmp = Cast<APuzzle_KeyboardInputs>(inputtedCharacters[i]);
//		//		if (tmp != nullptr)
//		//		{
//		//			UE_LOG(LogTemp, Warning, TEXT("Casted to input"));
//		//			tmp->inputCharacter = i;
//		//			tmp->LateStart();
//		//		}
//		//		else
//		//		{
//		//			UE_LOG(LogTemp, Warning, TEXT("failed to cast to input"));
//		//		}
//		//	}
//		//	else
//		//	{
//		//		UE_LOG(LogTemp, Warning, TEXT("failed to cast to actor"));
//		//	}
//		//	//inputtedCharacters[i]->inputCharacter = i;
//		//	//inputtedCharacters[i]->LateStart();
//		//}
//}

void APuzzle_Keyboard::GenerateRandomCode()
{
	//for (int32 i = 0; i <= 3; i++)
	//{
	//	generatedCode[i] = FMath::RandRange(0, 3);
	//	UE_LOG(LogTemp, Warning, TEXT("Int %d"), generatedCode[i]);
	//}

	//generatedCode[0] = 0;
	//generatedCode[1]= 3;
	//generatedCode[2] = 1;
	//generatedCode[3] = 2;

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

			FString objName = GetName();
			UE_LOG(LogTemp, Warning, TEXT("Generated Code Is %d %d %d %d"), generatedCode[0], generatedCode[1], generatedCode[2], generatedCode[3]);
			UE_LOG(LogTemp, Warning, TEXT("%s"), *objName);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("failed to cast to Textrender"));
		}
	}
}


void APuzzle_Keyboard::UnlockObject()
{

}
void APuzzle_Keyboard::LockObject()
{

}

//void APuzzle_Keyboard::AssignTextRenders()
//{
//	//if (monitor != NULL)
//	//{
//	//	UTextRenderComponent* editableText[] = {
//	//		Cast<UTextRenderComponent>(monitor->GetDefaultSubobjectByName(TEXT("InputChar1"))),
//	//		Cast<UTextRenderComponent>(monitor->GetDefaultSubobjectByName(TEXT("InputChar2"))),
//	//		Cast<UTextRenderComponent>(monitor->GetDefaultSubobjectByName(TEXT("InputChar3"))),
//	//		Cast<UTextRenderComponent>(monitor->GetDefaultSubobjectByName(TEXT("InputChar4"))),
//	//	};
//	//	for (size_t i = 0; i <= generatedCode.Num(); i++)
//	//	{
//	//		text.Add(editableText[i]);
//	//	}
//	//	UpdateMonitor(NULL, true);
//	//}
//}
//
//// Called every frame
//void APuzzle_Keyboard::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//}

//void APuzzle_Keyboard::KeyboardLogic(int32 inputedDigit)
//{
//	//if (puzzleIsComplete)
//	//{
//	//	return;
//	//}
//	//inputedCode[currentCodePos] = inputedDigit;
//	//UpdateMonitor(currentCodePos, false);
//	//currentCodePos++;
//	//if (currentCodePos == generatedCode.Num())
//	//{
//	//	UE_LOG(LogTemp, Warning, TEXT("Checking if code is correct"));
//	//	if (IsCodeCorrect())
//	//	{
//	//		UE_LOG(LogTemp, Warning, TEXT("Puzzle Complete"));
//	//		ShowMonitorScreen(true);
//	//		puzzleIsComplete = true;
//	//		//Cast the fuze puzzle to fuze puzzle
//	//		if (fuzePuzzle != nullptr)
//	//		{
//	//			AFuzePuzzle* tmp = Cast<AFuzePuzzle>(fuzePuzzle);
//	//			if (tmp != nullptr)
//	//			{
//	//				tmp->StartPuzzle();
//	//			}
//	//		}
//	//	}
//	//	else
//	//	{
//	//		//Restart Puzzle;
//	//		UE_LOG(LogTemp, Warning, TEXT("Restart Puzzle"));
//	//		currentCodePos = 0;
//	//		ShowMonitorScreen(false);
//	//		UpdateMonitor(NULL, true);
//	//	}
//	//}
//}
//void APuzzle_Keyboard::ShowMonitorScreen(bool codeOutcome)
//{
//	//UTextRenderComponent* outputText = Cast<UTextRenderComponent>(monitor->GetDefaultSubobjectByName(TEXT("txtError")));
//	//if (outputText != nullptr)
//	//{
//	//	outputText->SetVisibility(true);
//	//	//Wait for X seconds
//	//	if (codeOutcome)
//	//	{
//	//		//Puzzle Complete
//	//		outputText->SetText(FString(TEXT("Correct")));
//	//	}
//	//	else
//	//	{
//	//		
//	//		outputText->SetText(FString(TEXT("Incorrect")));
//	//	}
//	//	HideText(outputText, codeOutcome);
//	//}
//}

bool APuzzle_Keyboard::IsCodeCorrect()
{
	for (size_t i = 0; i < 4; i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("Inputed Code %d   %d"), inputedCode[i], generatedCode[i]);
		if (inputedCode[i] != generatedCode[i])
		{
			return false;
		}
	}
	return true;
}

//void APuzzle_Keyboard::UpdateMonitor(int currentCharacterIndex)
//{
//	
//}

void APuzzle_Keyboard::InputNewKey(const int32 characterToInput, AActor* characterThatHasInteracted)
{
	if (puzzleIsComplete)
		return;

	inputedCode[currentCodePos] = characterToInput;
	UE_LOG(LogTemp, Warning, TEXT("Inputed Code %d"), inputedCode[currentCodePos]);
	UpdateMonitor("*", currentCodePos);
	currentCodePos++;

	if (currentCodePos == generatedCode.Num())
	{
		if (IsCodeCorrect() == true)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("Puzzle Complete"));
			UE_LOG(LogTemp, Warning, TEXT("Puzzle Complete"));
			puzzleIsComplete = true;
			PuzzleIsComplete(characterThatHasInteracted);
		}
		else if (IsCodeCorrect() == false)
		{
			UE_LOG(LogTemp, Warning, TEXT("Puzzle Restart"));
			UE_LOG(LogTemp, Warning, TEXT("Inputted Code Was %d %d %d %d"), inputedCode[0], inputedCode[1], inputedCode[2], inputedCode[3]);
			UE_LOG(LogTemp, Warning, TEXT("Generated Code Was %d %d %d %d"), generatedCode[0], generatedCode[1], generatedCode[2], generatedCode[3]);
			//Restart Puzzle;
			for (size_t i = 0; i < 4; i++)
			{
				UpdateMonitor("_", i);
			}
			//FText::FromString(TEXT("*"))
			currentCodePos = 0;
		}
	}
}

void APuzzle_Keyboard::PuzzleIsComplete(AActor* characterThatHasInteracted)
{
	//Change The View of the player to the door
	AThirdPersonCharacter* character = Cast<AThirdPersonCharacter>(characterThatHasInteracted);
	if (character != nullptr)
	{
		APlayerController* playerController = Cast<APlayerController>(character->GetController());
		if (playerController != nullptr && cameraToChangeTo != nullptr)
		{
			playerController->SetViewTarget(cameraToChangeTo);
			ChangeCameraAfterDelay(characterThatHasInteracted);
			//FTimerHandle TimerHandle;
			//GetWorld()->GetTimerManager().SetTimer(TimerHandle,[&]() { this->ChangeCameraAfterDelay(playerController, character); },2.f,false,1.f);
		}
	}

	if (puzzleToUnlock == nullptr)
		return;

	AStaticObjects* puzzleToTrigger = Cast<AStaticObjects>(puzzleToUnlock);
	if (puzzleToTrigger != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Open Door"));
		puzzleToTrigger->UnlockObject();
	}


	//UTextRenderComponent* stickyNoteCode = Cast<UTextRenderComponent>(stickyNote->GetDefaultSubobjectByName(TEXT("txtCode")));
	//puzzleToUnlock 
}

//void APuzzle_Keyboard::ChangeCameraAfterDelay(APlayerController* playerController, AThirdPersonCharacter* character)
//{
//	//UE_LOG(LogTemp, Warning, TEXT("CHANGE VIEW"));
//
//	//AActor* characterAsActor = Cast<AActor>(character);
//	//if (characterAsActor != nullptr)
//	//{
//	//	playerController->SetViewTargetWithBlend(characterAsActor,0.1f);
//	//}
//}


