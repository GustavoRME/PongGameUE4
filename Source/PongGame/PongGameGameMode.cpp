// Copyright Epic Games, Inc. All Rights Reserved.

#include "PongGameGameMode.h"
#include "PongGameCharacter.h"

APongGameGameMode::APongGameGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = APongGameCharacter::StaticClass();	
}
