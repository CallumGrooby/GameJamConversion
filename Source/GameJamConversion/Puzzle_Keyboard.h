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

	class UTextRenderComponent* text[4]{0,0,0,0};

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void KeyboardLogic(int inputtedCode);
	bool IsCodeCorrect();
	void UpdateMonitor(int characterToInput);
};
