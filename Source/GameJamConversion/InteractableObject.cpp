// Fill out your copyright notice in the Description page of Project Settings.


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
		
		FVector handPosition = characterToFollow->GetActorLocation() + (characterToFollow->GetActorForwardVector() * 150.0f);
		SetActorLocation(handPosition);
	}
}

void AInteractableObject::Use()
{

}

void AInteractableObject::Drop()
{
	if (objectIsPickedUp)
	{
		objectIsPickedUp = false;
		//Drop Logic
		characterToFollow = NULL;
	}
}


