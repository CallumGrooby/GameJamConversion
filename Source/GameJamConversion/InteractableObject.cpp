// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractableMachine.h"
#include "InteractableObject.h"
#include "ThirdPersonCharacter.h"

// Sets default values
AInteractableObject::AInteractableObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInteractableObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInteractableObject::PickUp(AActor* pickedUpCharacter, bool doOnce)
{
	if (doOnce)
	{		
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, pickedUpCharacter->GetActorLabel());
		objectIsPickedUp = true;
		characterToFollow = pickedUpCharacter;
		doOnce = false;
		SetActorEnableCollision(false);
		return;
	}
	else
	{
		objectIsPickedUp = false;
	}
}

void AInteractableObject::FollowPlayer()
{
	if (objectIsPickedUp && characterToFollow != NULL)
	{ 
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, characterToFollow->GetActorLabel());
		FVector objPos;
		if (carryOnBack)
		{
			objPos = characterToFollow->GetActorLocation()+ (characterToFollow->GetActorForwardVector() * -90.0f);
			objPos.Z = objPos.Z + 20.0f;
		}
		else
		{
			objPos = characterToFollow->GetActorLocation() + (characterToFollow->GetActorForwardVector() * 90.0f);
		}
		
		FRotator objRot = characterToFollow->GetActorRotation();

		SetActorRotation(objRot);
		SetActorLocation(objPos);
	}
}

void AInteractableObject::Use(AInteractableMachine* interactableMachine)
{
	AActor* theOwner = this;
	if (theOwner != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("The owner is valid! Yuppie!"));
	}
	interactableMachine->MachineLogic(this);
}

void AInteractableObject::Drop()
{
	if (objectIsPickedUp)
	{
		SetActorEnableCollision(true);
		objectIsPickedUp = false;
		//Drop Logic
		characterToFollow = NULL;
	}
}


