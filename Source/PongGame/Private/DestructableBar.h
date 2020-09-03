// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DestructableBar.generated.h"


class UStaticMeshComponent;
class AScoreManager;

UCLASS()
class ADestructableBar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADestructableBar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	
	//Only fields
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere)
	AScoreManager* ScoreManager;

private:

	//Only functions
	UFUNCTION()
	void OnTriggerEnter(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
