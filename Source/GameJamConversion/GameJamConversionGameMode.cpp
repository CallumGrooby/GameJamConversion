// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameJamConversionGameMode.h"
#include "GameJamConversionCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGameJamConversionGameMode::AGameJamConversionGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
