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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InteractableObjects");
	bool objectIsPickedUp{ false };

	UFUNCTION(BlueprintCallable, Category = "InteractableObjects")
	void Move();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	AActor* characterToFollow;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void PickUp(AActor* character, bool doOnce);
	void Drop();
	void Use();
};
