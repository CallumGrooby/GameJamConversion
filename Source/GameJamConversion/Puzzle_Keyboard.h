// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ThirdPersonCharacter.h"
#include "Components/TextRenderComponent.h"
#include <string>
#include "Puzzle_Keyboard.generated.h"

UCLASS()
class GAMEJAMCONVERSION_API APuzzle_Keyboard : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APuzzle_Keyboard();


	//void KeyboardLogic(int32 inputtedCode);
	
	//void ShowMonitorScreen(bool codeOutcome);
	UFUNCTION(BlueprintImplementableEvent, Category = "Events")
	void UpdateMonitor(const FString& s, int characterToInput);
	//UFUNCTION(BlueprintImplementableEvent, Category = "Events")
	//	void HideText(UTextRenderComponent* outputText, bool isPuzzleComplete);
	//UFUNCTION(BlueprintImplementableEvent, Category = "Events")
	//	void EndPuzzle();

	bool IsCodeCorrect();
	void InputNewKey(int32 characterToInput, AActor* characterThatHasInteracted);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	int currentCodePos;
	//UFUNCTION()
	void GenerateRandomCode();
	//void AssignTextRenders();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	bool puzzleIsComplete = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unasigned Actors")
		TArray<UTextRenderComponent*> textRenders;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unasigned Actors")
		AActor* monitor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unasigned Actors")
		AActor* cameraToChangeTo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unasigned Actors")
		AActor* stickyNote;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrays")
		TArray<AActor*> inputSlots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrays")
		TArray<int32> generatedCode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrays")
		TArray<int32> inputedCode;

};
