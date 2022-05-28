// Copyright Epic Games, Inc. All Rights Reserved.

#include "Aghanim_RPGGameMode.h"
#include "Aghanim_RPGCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAghanim_RPGGameMode::AAghanim_RPGGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
