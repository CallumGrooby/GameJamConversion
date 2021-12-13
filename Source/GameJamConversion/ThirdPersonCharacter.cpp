// Fill out your copyright notice in the Description page of Project Settings.

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT(text), fstring))
#include "InteractableObject.h"
#include "InteractableMachine.h"
#include "GameFramework/Controller.h"
#include "ThirdPersonCharacter.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"


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
	APlayerController* ourPlayerController = UGameplayStatics::GetPlayerController(this, 0);
	PlayersCamera = ourPlayerController->GetViewTarget();
}

// Called every frame
void AThirdPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Switching CameraLogic
	//timeToNextCameraChange -= DeltaTime;
	//if (timeToNextCameraChange <= 0.0f)
	//{
	//	timeToNextCameraChange += TimeBetweenCameraChanges;

	//	APlayerController* ourPlayerController = UGameplayStatics::GetPlayerController(this,0);

	//	if (ourPlayerController)
	//	{
	//		if (CameraTwo && (ourPlayerController->GetViewTarget()== CameraPlayer))
	//		{
	//			ourPlayerController->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
	//		}
	//		else if (CameraPlayer)
	//		{
	//			ourPlayerController->SetViewTarget(CameraPlayer);
	//		}
	//	}
	//}
}

void AThirdPersonCharacter::ChangeCamera(AActor* CameraToChangeTo)
{
	APlayerController* ourPlayerController = UGameplayStatics::GetPlayerController(this, 0);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("is working"));
	if (ourPlayerController)
	{
		if (CameraToChangeTo && (ourPlayerController->GetViewTarget() == PlayersCamera))
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("change to non character"));
			ourPlayerController->SetViewTargetWithBlend(CameraToChangeTo, SmoothBlendTime);
		}
		else if (PlayersCamera)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("player camera"));
			ourPlayerController->SetViewTarget(PlayersCamera);
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("failed to get character"));
	}
}

// Called to bind functionality to input
void AThirdPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

AInteractableObject* AThirdPersonCharacter::PickUpObject()
{
	APlayerCameraManager* camManager = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;
	FVector camLocation = camManager->GetCameraLocation();
	FRotator camForward = camManager->GetCameraRotation();

	FHitResult hit = CastRay(camLocation, camForward);
	AInteractableObject* interactableObject = Cast<AInteractableObject>(hit.Actor);

	if (interactableObject)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Interactable Object"));
		return interactableObject;
	}

	return NULL;
}

void AThirdPersonCharacter::UseObject()
{
	APlayerCameraManager* camManager = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;
	FVector camLocation = camManager->GetCameraLocation();
	FRotator camForward = camManager->GetCameraRotation();

	FHitResult hit = CastRay(camLocation, camForward);

	AInteractableMachine* interactableMachine = Cast<AInteractableMachine>(hit.Actor);
	UE_LOG(LogTemp, Warning, TEXT("Use Object"));
	if (interactableMachine != NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Interactable"));
		pickedupObject->Use(interactableMachine);
		DropObject();
	}
}



void AThirdPersonCharacter::DropObject()
{
	if (pickedupObject != NULL)
	{
		pickedupObject->Drop();
		pickedupObject = NULL;
	}
}

void AThirdPersonCharacter::PickUpLogic()
{
	if (pickedupObject == NULL)
		return;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, pickedupObject->GetActorLabel());
	pickedupObject->PickUp(this, true);
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

