// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Math/Vector.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

UCLASS()
class HW1_API ACppBaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppBaseActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void SinMovement();

	UPROPERTY(VisibleAnywhere)
	FString PlayerName = "Vasya";
	UPROPERTY(EditAnywhere)
	int EnemyNum = 15;
	UPROPERTY(EditAnywhere)
	float CurrentHealth = 50;
	UPROPERTY(EditInstanceOnly)
	bool IsAlive = true;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnywhere)
	float Amplitude = 50;
	UPROPERTY(EditAnywhere)
	float Frequency = 4;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private: 
	void ShowActorInformation();
	FVector InitialLocation;

};
