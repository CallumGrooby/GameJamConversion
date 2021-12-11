// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableMachine.h"
#include "FuzePuzzle.h"
#include "InteractiveLeaver.h"
#include "InteractableFuze.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAMCONVERSION_API AInteractableFuze : public AInteractableMachine
{
	GENERATED_BODY()

public:
	AInteractableFuze();
	void MachineLogic(AActor* interactableObject) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* machineToStop;

protected:

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
