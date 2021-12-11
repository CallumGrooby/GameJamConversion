// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractiveLeaver.h"

AInteractiveLeaver::AInteractiveLeaver()
{

}

void AInteractiveLeaver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInteractiveLeaver::MachineLogic(AActor* interactableObject)
{
	UE_LOG(LogTemp, Warning, TEXT("LEAVER"));
	if (machineToStop == nullptr)
		return;

	AInteractableFan* fanObj = Cast<AInteractableFan>(machineToStop);
	if (fanObj != nullptr)
	{
		fanObj->endLogic = true;
	}
	//AAInteractableFan 
		//.endLogic = true;
//	UTextRenderComponent* editableText[] = {
	//Cast<UTextRenderComponent>(monitor->GetDefaultSubobjectByName(TEXT("InputChar1")))

	//Stop the fan from spinning
	// Reference to the fan object
	//Call a stop spinning method
}


