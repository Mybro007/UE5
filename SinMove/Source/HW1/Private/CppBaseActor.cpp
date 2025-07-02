// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ACppBaseActor::ACppBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation = GetActorLocation();
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACppBaseActor::ShowActorInformation()
{	
	UE_LOG(LogTemp, Display, TEXT("Instance name: %s"), *PlayerName);
	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);
}

void ACppBaseActor::SinMovement()
{
	// Расчёт новой Z-координаты по закону синуса
	float Time = GetWorld()->GetTimeSeconds();
	float NewZ = InitialLocation.Z + Amplitude * FMath::Sin(Frequency * Time);

	// Обновляем позицию актора
	FVector NewLocation = GetActorLocation();
	NewLocation.Z = NewZ;
	SetActorLocation(NewLocation);
}