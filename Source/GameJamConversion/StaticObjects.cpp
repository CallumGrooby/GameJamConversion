// Fill out your copyright notice in the Description page of Project Settings.


#include "StaticObjects.h"

// Sets default values
AStaticObjects::AStaticObjects()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStaticObjects::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStaticObjects::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStaticObjects::UnlockObject()
{

}

void AStaticObjects::LockObject()
{

}

