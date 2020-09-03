// Fill out your copyright notice in the Description page of Project Settings.


#include "BallController.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABallController::ABallController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetCollisionProfileName("Trigger");
	StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &ABallController::OnTriggerEnter);

	StaticMesh->SetupAttachment(RootComponent);

	Direction = FVector(0.0f);
	StartPosition = FVector(0.0f);

	Speed = 100.0f;
	StartSpeed = Speed;
	Acceleration = 2.0f;

	MaxSpeed = 500.0f;

	//Min
	MinHorizontal = 0.0f;
	MinVertical = 0.0f;

	//Max
	MaxHorizontal = 0.0f;
	MaxVertical = 0.0f;
}

// Called when the game starts or when spawned
void ABallController::BeginPlay()
{
	Super::BeginPlay();
	
	StartSpeed = Speed;
	StartPosition = GetActorLocation();
	Direction.Set(0.0f, FMath::RandRange(-1.0, 1.0f), -1.0f);
}

// Called every frame
void ABallController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!Direction.IsZero())
	{
		FVector CurrentPosition = GetActorLocation();

		FVector Velocity = Direction * Speed * DeltaTime;

		//Horizontal Clamp
		CurrentPosition.Y = FMath::Clamp(Velocity.Y + CurrentPosition.Y, MinHorizontal, MaxHorizontal);

		//When reach the walls on sides
		if (CurrentPosition.Y == MinHorizontal)
		{
			//Go right
			Direction.Y = 1.0f;
		}
		else if (CurrentPosition.Y == MaxHorizontal)
		{
			//Go right
			Direction.Y = -1.0f;
		}

		//Vertical Clamp
		CurrentPosition.Z = FMath::Clamp(Velocity.Z + CurrentPosition.Z, MinVertical, MaxVertical);

		//When reach the upper or bottom walls
		if (CurrentPosition.Z == MaxVertical)
		{
			//Go down
			Direction.Z = -1.0f;
		}
		else if (CurrentPosition.Z == MinVertical)
		{
			//Reset all parameters
			CurrentPosition = StartPosition;
			Speed = StartSpeed;
			Direction.Set(0.0f, FMath::RandRange(-1.0, 1.0f), -1.0f);
		}

		SetActorLocation(CurrentPosition);
	}

}

void ABallController::OnTriggerEnter(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != this)
	{
		float Yaw = 0.0f;
		float Pitch = 0.0f;

		if (OtherActor)
		{
			FVector CurrentPosition = GetActorLocation();
			FVector OtherPosition = OtherActor->GetActorLocation();

			//Collision at upper
			if (OtherPosition.Z > CurrentPosition.Z)
			{
				//Go down
				Yaw = -1.0f;
			}
			else //Collision at bottom
			{
				//Go up
				Yaw = 1.0f;
			}

			//Collision at left
			if (OtherPosition.Y > CurrentPosition.Y)
			{
				//Go to left
				Pitch = FMath::RandRange(0.0f, -1.0f);
			}			
			else //Collision at Right
			{
				//Go to right
				Pitch = FMath::RandRange(0.0f, 1.0f);
			}
		}
		
		//Increase speed with acceleration withou pass max speed
		Speed = FMath::Clamp(Speed + Acceleration, 1.0f, MaxSpeed);

		//Set direction
		Direction.Set(0.0f, Pitch, Yaw);		
	}
}

