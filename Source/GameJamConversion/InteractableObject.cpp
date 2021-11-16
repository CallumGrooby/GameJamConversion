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
		pickedUpCharacter = characterToFollow;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, pickedUpCharacter->GetActorLabel());
		
		objectIsPickedUp = true;
		doOnce = false;
	}
}

void AInteractableObject::Move()
{
	if (objectIsPickedUp && characterToFollow != NULL)
	{
		SetActorLocation(characterToFollow->GetActorLocation());
	}
}

void AInteractableObject::Use()
{

}

void AInteractableObject::Drop()
{

}


