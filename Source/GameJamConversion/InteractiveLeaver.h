// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Math/UnrealMathUtility.h"
#include "Components/BoxComponent.h"
#include "InteractableMachine.h"
#include "InteractableFan.h"
#include "InteractiveLeaver.generated.h"

UCLASS()
class GAMEJAMCONVERSION_API AInteractiveLeaver : public AInteractableMachine
{
	GENERATED_BODY()

public:
	AInteractiveLeaver();
	void MachineLogic(AActor* interactableObject) override;
	UFUNCTION(BlueprintCallable, Category = "InteractableObjects")
		void rotateLever(UStaticMeshComponent* Lever, float DeltaTime);
	UFUNCTION(BlueprintCallable, Category = "InteractableObjects")
		void moveHitbox(UBoxComponent* hitBox, float DeltaTime);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* lightToToggle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FRotator targetRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector hitBoxStartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isInBox;
	bool doOnce;

protected:
	virtual void BeginPlay() override;



public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
