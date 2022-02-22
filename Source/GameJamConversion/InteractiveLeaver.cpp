// Fill out your copyright notice in the Description page of Project Settings.

#include "Math/UnrealMathUtility.h"
#include "Components/BoxComponent.h"
#include "InteractiveLeaver.h"

AInteractiveLeaver::AInteractiveLeaver()
{
	targetRotation = FRotator(0, 0, 0);
	doOnce = true;
}

void AInteractiveLeaver::BeginPlay()
{
	Super::BeginPlay();
	targetRotation = FRotator(0, 0, 0);

}


void AInteractiveLeaver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}



void AInteractiveLeaver::MachineLogic(AActor* interactableObject)
{
	UE_LOG(LogTemp, Warning, TEXT("LEAVER"));
}

void AInteractiveLeaver::rotateLever(UStaticMeshComponent* Lever, float DeltaTime)
{
	FRotator leverRot = Lever->GetComponentRotation();
	FRotator rotation = FMath::RInterpTo(leverRot, targetRotation, DeltaTime, 1.0f);

	Lever->SetWorldRotation(rotation);

	FRotator currentleverRotation = Lever->GetComponentRotation();
	//if (currentleverRotation.Pitch >= 55.0 && doOnce)
	//{
	//	doOnce = false;
	//	if (lightToToggle != nullptr)
	//	{

	//	}
	//}
	//else
	//{
	//	doOnce = true;
	//}
}

void AInteractiveLeaver::moveHitbox(UBoxComponent* hitBox, float DeltaTime)
{
	FVector hitBoxLocation = hitBox->GetComponentLocation();
	FVector desitation;

	if (isInBox)
	{
		desitation = FVector((DeltaTime * -5.0f) + hitBoxLocation.X, hitBoxLocation.Y, hitBoxLocation.Z);
		hitBox->SetWorldLocation(desitation);
	}
	else if (!isInBox && !(hitBoxLocation.X == hitBoxStartLocation.X))
	{
		desitation = FMath::VInterpTo(hitBoxLocation, hitBoxStartLocation, DeltaTime, 1.0f);
		hitBox->SetWorldLocation(desitation);
	}
}


