// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableMachine.generated.h"

UCLASS()
class GAMEJAMCONVERSION_API AInteractableMachine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractableMachine();
	UFUNCTION(BlueprintCallable, Category = "InteractableObjects")
		virtual void MachineLogic(AActor* interactableObject);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ini")
		void EventSoundCue();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
