// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BallController.generated.h"

class UStaticMeshComponent;

UCLASS()
class ABallController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:	
	
	//Only variables	
	FVector Direction;
	FVector StartPosition;
	float StartSpeed;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float Speed;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float Acceleration;

	UPROPERTY(EditAnywhere, Category = "Boundaries")
	float MaxSpeed;

	UPROPERTY(EditAnywhere, Category = "Boundaries")
	float MinHorizontal;

	UPROPERTY(EditAnywhere, Category = "Boundaries")
	float MaxHorizontal;

	UPROPERTY(EditAnywhere, Category = "Boundaries")
	float MinVertical;

	UPROPERTY(EditAnywhere, Category = "Boundaries")
	float MaxVertical;

private:
	
	//Only methods
	UFUNCTION()
	void OnTriggerEnter(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
