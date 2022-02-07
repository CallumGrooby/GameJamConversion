// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractiveLeaver.h"

AInteractiveLeaver::AInteractiveLeaver()
{

}

void AInteractiveLeaver::BeginPlay()
{
	Super::BeginPlay();

}

void AInteractiveLeaver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInteractiveLeaver::MachineLogic(AActor* interactableObject)
{
	UE_LOG(LogTemp, Warning, TEXT("LEAVER"));
	
	
}


