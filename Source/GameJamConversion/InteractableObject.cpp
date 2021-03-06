// Fill out your copyright notice in the Description page of Project Settings.

// Fill out your copyright notice in the Description page of Project Settings.
#include "InteractableObject.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/Actor.h"
#include "DrawDebugHelpers.h"

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

	//Get the static mesh of the object and then get the scale of that 
	// scale / 2 + 0.01;

	FVector objScale = GetActorScale3D();
	float height = (objScale.Z / 2) + 0.1;
	convertedHeight = height * 100;
	UE_LOG(LogTemp, Warning, TEXT("height = %f"), convertedHeight);
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
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, pickedUpCharacter->GetActorLabel());
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
			objPos = characterToFollow->GetActorLocation() + (characterToFollow->GetActorForwardVector() * -90.0f);
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

//void AInteractableObject::Use(AInteractableMachine* interactableMachine)
//{
//	AActor* theOwner = this;
//	if (theOwner != nullptr)
//	{
//		//UE_LOG(LogTemp, Warning, TEXT("The owner is valid! Yuppie!"));
//	}
//	interactableMachine->MachineLogic(this);
//}

void AInteractableObject::Drop()
{
	if (objectIsPickedUp)
	{
		SetActorEnableCollision(true);
		objectIsPickedUp = false;
		//Drop Logic
		FVector dropLocation = CalcDropLocation();
		//UE_LOG(LogTemp, Warning, TEXT("PhysicsHandle working %s"), *dropLocation.ToString());
		SetActorLocation(FMath::Lerp(GetActorLocation(), dropLocation, 0.5f));
		characterToFollow = NULL;
		//Slerp to location
	}
}

FHitResult AInteractableObject::CastRay(FVector rayLocation, FRotator rayRotation, float castRange)
{
	FVector endTrace = FVector::ZeroVector;
	endTrace = rayLocation + (rayRotation.Vector() * castRange);
	DrawDebugLine(GetWorld(), rayLocation, endTrace, FColor::Emerald, false, 0.5f, 0, 1);
	FCollisionQueryParams traceParams(SCENE_QUERY_STAT(instantShot), true, GetInstigator());
	FHitResult hit(ForceInit);
	GetWorld()->LineTraceSingleByChannel(hit, rayLocation, endTrace, ECC_Visibility, traceParams);

	return hit;
}

FVector AInteractableObject::CalcDropLocation()
{
	FHitResult hit = CastRay(GetActorLocation(), FRotator(270, 0, 0), 1000);
	return hit.Location;
}