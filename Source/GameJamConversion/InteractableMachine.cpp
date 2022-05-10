// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractableMachine.h"
#include "FuzePuzzle.h"


// Sets default values
AInteractableMachine::AInteractableMachine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInteractableMachine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractableMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractableMachine::MachineLogic(AActor* interactableObject)
{
	//UE_LOG(LogTemp, Warning, TEXT("MachineLogic"));
	//if (!GetParentActor())
	//	return;
	////Get Parent Object
	//AActor* machineObj = GetParentActor();

	//AFuzePuzzle* fuse = Cast<AFuzePuzzle>(machineObj);
	//if (fuse == nullptr)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Machine Logic Cast failed"));
	//	return;
	//}

	//UE_LOG(LogTemp, Warning, TEXT("Machine Logic Cast Successful"));

	//if (interactableObject != nullptr)
	//{
	//	UE_LOG(LogClass, Log, TEXT("This a testing statement"));
	//	interactableObject->Destroy();
	//}

	//fuse->RunLogic();
}

void AInteractableMachine::EventSoundCue_Implementation() {
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("This is an on screen message!"));
}

