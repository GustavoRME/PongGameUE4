// Fill out your copyright notice in the Description page of Project Settings.


#include "DestructableBar.h"
#include "Components/StaticMeshComponent.h"
#include "EngineUtils.h"
#include "ScoreManager.h"
#include "UObject/UObjectIterator.h"


// Sets default values
ADestructableBar::ADestructableBar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	ScoreManager = NULL;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetCollisionProfileName("Trigger");
	StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &ADestructableBar::OnTriggerEnter);

	StaticMesh->SetupAttachment(RootComponent);

	//-------Add mesh from file--------
	
	//Get a trim from files
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BoxAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Trim.Shape_Trim'"));

	//Check if was succedded
	if (BoxAsset.Succeeded())
	{
		//Set static mesh
		StaticMesh->SetStaticMesh(BoxAsset.Object);
		//Set relative location from root
		StaticMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		//Set scale
		StaticMesh->SetWorldScale3D(FVector(1.0f));
	}
}

// Called when the game starts or when spawned
void ADestructableBar::BeginPlay()
{
	Super::BeginPlay();
			
}

// Called every frame
void ADestructableBar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADestructableBar::OnTriggerEnter(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != this)
	{
		if (ScoreManager)
		{
			ScoreManager->IncreaseScore();
		}

		SetActorHiddenInGame(true);

		SetActorEnableCollision(false);

		SetActorTickEnabled(false);
	}
}

