// Fill out your copyright notice in the Description page of Project Settings.


#include "LockedDoorLogic.h"

// Sets default values
ALockedDoorLogic::ALockedDoorLogic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
// Called when the game starts or when spawned
void ALockedDoorLogic::BeginPlay()
{
	Super::BeginPlay();
	//isActive = false;
}

// Called every frame
void ALockedDoorLogic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RotateToPoint(DeltaTime);
}

void ALockedDoorLogic::UnlockObject()
{
	isActive = true;
}


void ALockedDoorLogic::RotateToPoint(float DeltaTime)
{
	if (!isActive)
		return;

	FRotator currentRotation = this->GetActorRotation();
	FRotator rotation = FMath::RInterpTo(currentRotation, targetRotation, DeltaTime, rotationSpeed);
	this->SetActorRotation(rotation);
}



