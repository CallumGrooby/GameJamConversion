// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableObject.generated.h"

UCLASS()
class GAMEJAMCONVERSION_API AInteractableObject : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AInteractableObject();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool objectIsPickedUp{ false };
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool carryOnBack{ false };
	UFUNCTION(BlueprintCallable, Category = "InteractableObjects")
		FVector CalcDropLocation();
	UFUNCTION(BlueprintCallable, Category = "InteractableObjects")
		void FollowPlayer();
	AActor* characterToFollow;
	float convertedHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		float rayCastRange{ 1000 };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void PickUp(AActor* character, bool doOnce);
	virtual void Drop();
	//virtual void Use(AInteractableMachine* interactableMachine);
	FHitResult CastRay(FVector rayLocation, FRotator rayRotation, float castRange);
};
