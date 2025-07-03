// LeaveMeAlone Game by Netologiya. All RightsReserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LMADefaultCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class ULMAHealthComponent;
class UAnimMontage;

UCLASS(Blueprintable)
class LEAVEMEALONE_API ALMADefaultCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALMADefaultCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Обработчики ввода
	void OnSprintPressed();
	void OnSprintReleased();

	// Таймеры для обновления выносливости
	void HandleStaminaDrain();
	void HandleStaminaRecovery();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArmComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* CameraComponent;
	UPROPERTY()
	UDecalComponent* CurrentCursor = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	UMaterialInterface* CursorMaterial = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	FVector CursorSize = FVector(20.0f, 40.0f, 40.0f);
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components|Health")
	ULMAHealthComponent* HealthComponent;
	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	UAnimMontage* DeathMontage;

	// Выносливость
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stamina")
	float MaxStamina = 100.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stamina")
	float CurrentStamina;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stamina")
	float StaminaDrainRate = 20.0f;  // Скорость траты выносливости
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stamina")
	float StaminaGainRate = 15.0f;    // Скорость восстановления
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stamina")
	float MinStaminaToSprint = 20.0f; // Минимальная выносливость для спринта
	FTimerHandle StaminaTimerHandle; // Таймер для управления выносливостью

	// Флаги состояний
	bool bIsSprinting = false;
	bool bWantsToSprint = false;

private:
	float YRotation = -75.0f;
	float ArmLength = 1400.0f;
	float FOV = 55.0f;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void OnDeath();
	void RotationPlayerOnCursor();
	void OnHealthChanged(float NewHealth);
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	ULMAHealthComponent* GetHealthComponent() const { return HealthComponent; };

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void StartSprinting();

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void StopSprinting();

	UFUNCTION(BlueprintPure, Category = "Movement")
	bool CanSprint() const;
};
