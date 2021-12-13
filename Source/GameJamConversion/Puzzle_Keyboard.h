// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Puzzle_Keyboard.generated.h"

UCLASS()
class GAMEJAMCONVERSION_API APuzzle_Keyboard : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APuzzle_Keyboard();


	void KeyboardLogic(int32 inputtedCode);
	bool IsCodeCorrect();
	void ShowMonitorScreen(bool codeOutcome);
	void UpdateMonitor(int characterToInput, bool doOnce);
	UFUNCTION(BlueprintImplementableEvent, Category = "Events")
		void HideText(UTextRenderComponent* outputText);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	int currentCodePos;
	void AssignInputs();
	void GenerateRandomCode();
	void AssignTextRenders();
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	bool puzzleIsComplete = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unasigned Actors")
		AActor* monitor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unasigned Actors")
		AActor* fuzePuzzle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unasigned Actors")
		AActor* stickyNote;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Code")
	//	int32 codeToInputFromMesh1 = 0;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Code")
	//	int32 codeToInputFromMesh2 = 1;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Code")
	//	int32 codeToInputFromMesh3 = 2;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Code")
	//	int32 codeToInputFromMesh4 = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrays")
		TArray<AActor*> inputSlots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrays")
		TArray<int32> generatedCode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrays")
		TArray<int32> inputedCode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arrays")
		TArray<class UTextRenderComponent*>  text;
};
