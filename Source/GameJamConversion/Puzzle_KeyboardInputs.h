// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Puzzle_Keyboard.h"
#include "Puzzle_KeyboardInputs.generated.h"


UCLASS()
class GAMEJAMCONVERSION_API APuzzle_KeyboardInputs : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APuzzle_KeyboardInputs();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Puzzle_KeyboardInputs")
		int32 inputCharacter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Puzzle_KeyboardInputs")
		AActor* monitorActor;
	UFUNCTION(BlueprintCallable, Category = "Puzzle_KeyboardInputs")
		void InputNewKey(int32 characterToInput, AActor* playerActor);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	APuzzle_Keyboard* monitorScript;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
