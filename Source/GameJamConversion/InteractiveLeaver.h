// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableMachine.h"
#include "InteractiveLeaver.generated.h"

UCLASS()
class GAMEJAMCONVERSION_API AInteractiveLeaver : public AInteractableMachine
{
	GENERATED_BODY()

public:
	AInteractiveLeaver();
	void MachineLogic(AActor* interactableObject) override;


protected:


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
