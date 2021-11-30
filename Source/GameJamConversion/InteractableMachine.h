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
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool testFunction{ false };
	UFUNCTION(BlueprintCallable, Category = "InteractableObjects")
		void MachineLogic(AActor* interactableObject);
	UFUNCTION(BlueprintImplementableEvent, Category = "InteractableObjects")
		void RunLogic();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
