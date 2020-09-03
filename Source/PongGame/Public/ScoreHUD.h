// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ScoreHUD.generated.h"

class UUserWidget;

/**
 * 
 */
UCLASS()
class PONGGAME_API AScoreHUD : public AHUD
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere)
	UUserWidget* UserWidget;
		
};
