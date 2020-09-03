// Fill out your copyright notice in the Description page of Project Settings.


#include "SlideBarController.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASlideBarController::ASlideBarController()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetCollisionProfileName("Trigger");	

	StaticMesh->SetupAttachment(RootComponent);	

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	//Set float
	Speed = 100.0f;
	MinHorizontal = -350.0f;
	MaxHorizontal = 350.0f;

	//FVector
	Axis = FVector(0.0f);
}

// Called when the game starts or when spawned
void ASlideBarController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASlideBarController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!Axis.IsZero())
	{
		FVector CurrentPosition = GetActorLocation();

		CurrentPosition += Axis * Speed * DeltaTime;

		CurrentPosition.Y = FMath::Clamp(CurrentPosition.Y, MinHorizontal, MaxHorizontal);

		SetActorLocation(CurrentPosition);
	}		
}

// Called to bind functionality to input
void ASlideBarController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &ASlideBarController::MoveRight);

}

void ASlideBarController::MoveRight(float AxisValue)
{
	Axis.Set(0.0f, AxisValue, 0.0f);
}
