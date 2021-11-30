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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Monitor")
		AActor* monitor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Code")
		TArray<int32> generatedCode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Code")
		TArray<int32> inputedCode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Code")
		TArray<class UTextRenderComponent*>  text;


	void KeyboardLogic(int32 inputtedCode);
	bool IsCodeCorrect();
	void ShowMonitorScreen(bool codeOutcome);
	void UpdateMonitor(int characterToInput, bool doOnce);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	int currentCodePos;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
