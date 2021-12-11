// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ThirdPersonCharacter.h"
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
	void FollowPlayer();
	AActor* characterToFollow;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void PickUp(AActor* character, bool doOnce);
	virtual void Drop();
	virtual void Use();
};
