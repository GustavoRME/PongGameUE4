// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreManager.h"

// Sets default values
AScoreManager::AScoreManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Score = 0;
	MaxScore = Score;	

	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	SetActorTickEnabled(false);
}

// Called when the game starts or when spawned
void AScoreManager::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AScoreManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AScoreManager::IncreaseScore()
{
	Score = FMath::Clamp(Score + 1, 0, MaxScore);
}

