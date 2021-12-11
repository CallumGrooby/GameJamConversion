// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InteractableObject.h"
#include "InteractableMachine.h"
#include "GameFramework/Controller.h"
#include "ThirdPersonCharacter.generated.h"

UCLASS()
class GAMEJAMCONVERSION_API AThirdPersonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AThirdPersonCharacter();

//Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		float rayCastRange{1000};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AInteractableObject* pickedupObject;

//Functions
	UFUNCTION(BlueprintCallable, Category = "InteractableObjects")
		AInteractableObject* PickUpObject();
	UFUNCTION(BlueprintCallable, Category = "InteractableObjects")
		void PickUpLogic();
	UFUNCTION(BlueprintCallable, Category = "InteractableObjects")
		void DropObject();
	UFUNCTION(BlueprintCallable, Category = "InteractableObjects")
		void UseObject();

	UFUNCTION(BlueprintCallable, Category = "Camera Settings")
		void ChangeCamera(AActor* CameraToChangeTo);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FHitResult CastRay(FVector rayLocation, FRotator rayRotation);

	FVector LocationOne{ 10, 0, 0 };
	FVector LocationTwo{ 0, 10, 0 };

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Camera Controller
	UPROPERTY(EditAnywhere)
		AActor* CameraPlayer;

	UPROPERTY(EditAnywhere)
		AActor* CameraTwo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Settings")
	float timeToNextCameraChange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Settings")
	float TimeBetweenCameraChanges = 2.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Settings")
	float SmoothBlendTime = 0.75;
};
