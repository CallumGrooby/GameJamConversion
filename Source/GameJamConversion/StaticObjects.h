// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StaticObjects.generated.h"

UCLASS()
class GAMEJAMCONVERSION_API AStaticObjects : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStaticObjects();

	virtual void UnlockObject();
	virtual void LockObject();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unlock")
	bool isActive;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
