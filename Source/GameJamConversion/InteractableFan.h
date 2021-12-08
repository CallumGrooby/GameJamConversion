// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableMachine.h"
#include "InteractableFan.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAMCONVERSION_API AInteractableFan : public AInteractableMachine
{
	GENERATED_BODY()
	
public:
	AInteractableFan();
	void AddRotation(float deltaTime);
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float rotationSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool endLogic;

protected:


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
