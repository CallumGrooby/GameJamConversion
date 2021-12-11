// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableFan.h"

AInteractableFan::AInteractableFan()
{

}

void AInteractableFan::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!endLogic)
	{
		AddRotation(DeltaTime);
	}
	else if (endLogic && doOnce)
	{
		//Rotate to Currect Position
		EventSoundCue();
	}
}

void AInteractableFan::AddRotation(float deltaTime)
{
	//if lever has been pulled

	AddActorLocalRotation(FRotator(0, deltaTime * rotationSpeed, 0));
}
