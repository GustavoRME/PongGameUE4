// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SlideBarController.generated.h"

class UStaticMeshComponent;

UCLASS()
class PONGGAME_API ASlideBarController : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASlideBarController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	FVector Axis;

private:

	UPROPERTY()
	UStaticMeshComponent* StaticMesh;	
	
	UPROPERTY(EditAnywhere)
	float Speed;		

	UPROPERTY(EditAnywhere, Category = "Boundaries")
	float MinHorizontal;
	
	UPROPERTY(EditAnywhere, Category = "Boundaries")
	float MaxHorizontal;	

	
	void MoveRight(float AxisValue);	
};
