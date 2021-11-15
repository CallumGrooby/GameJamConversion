// Fill out your copyright notice in the Description page of Project Settings.

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT(text), fstring))
#include "InteractableObject.h"
#include "ThirdPersonCharacter.h"
#include "DrawDebugHelpers.h"


// Sets default values
AThirdPersonCharacter::AThirdPersonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AThirdPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AThirdPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AThirdPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

AInteractableObject* AThirdPersonCharacter::PickUpObject()
{
	DrawDebugLine(GetWorld(), LocationOne, LocationTwo, FColor::Black, true, -1, 0, 10);
	FHitResult hit = CastRay(GetActorLocation(), GetActorRotation());
	AInteractableObject* interactableObject = Cast<AInteractableObject>(hit.Actor);

	if (interactableObject)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Interactable Object"));
		return interactableObject;
	}

	return NULL;
}

void AThirdPersonCharacter::PickUpLogic()
{
	if (pickedupObject == NULL)
		return;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, pickedupObject->GetActorLabel());


}


FHitResult AThirdPersonCharacter::CastRay(FVector rayLocation, FRotator rayRotation)
{
	FVector endTrace = FVector::ZeroVector;
	endTrace = rayLocation + (rayRotation.Vector() * rayCastRange);
	DrawDebugLine(GetWorld(), rayLocation, endTrace, FColor::Emerald, false, 0.5f, 0, 1);
	FCollisionQueryParams traceParams(SCENE_QUERY_STAT(instantShot), true, GetInstigator());
	FHitResult hit(ForceInit);
	GetWorld()->LineTraceSingleByChannel(hit, rayLocation, endTrace, ECC_Visibility, traceParams);

	return hit;
}

