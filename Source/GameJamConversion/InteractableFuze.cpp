// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableFuze.h"

AInteractableFuze::AInteractableFuze()
{

}

void AInteractableFuze::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInteractableFuze::MachineLogic(AActor* interactableObject)
{
	UE_LOG(LogTemp, Warning, TEXT("MachineLogic"));
	if (!GetParentActor())
		return;
	//Get Parent Object
	AActor* machineObj = GetParentActor();

	AFuzePuzzle* fuse = Cast<AFuzePuzzle>(machineObj);
	if (fuse == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Machine Logic Cast failed"));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Machine Logic Cast Successful"));

	if (interactableObject != nullptr)
	{
		UE_LOG(LogClass, Log, TEXT("This a testing statement"));
		interactableObject->Destroy();
	}

	fuse->RunLogic();

	AInteractiveLeaver* leaver = Cast<AInteractiveLeaver>(machineToStop);
	if (leaver != nullptr)
	{
		leaver->activateLever = true;
	}
}
