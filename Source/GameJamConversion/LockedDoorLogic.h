// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StaticObjects.h"
#include "LockedDoorLogic.generated.h"

UCLASS()
class GAMEJAMCONVERSION_API ALockedDoorLogic : public AStaticObjects
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ALockedDoorLogic();

	virtual void UnlockObject() override;
	void RotateToPoint(float DeltaTime);
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FRotator targetRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float rotationSpeed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//bool isActive;

};
