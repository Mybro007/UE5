// LeaveMeAlone Game by Netologiya. All RightsReserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/LMAHealthComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "LMAEnemyCharacter.generated.h"

class ULMAHealthComponent;
class UBehaviorTree;

UCLASS()
class LEAVEMEALONE_API ALMAEnemyCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ALMAEnemyCharacter();

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
    UBehaviorTree* BehaviorTreeAsset;

    // ƒобавл€ем новые свойства дл€ скорости
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
    float RunSpeed = 600.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
    float WalkSpeed = 300.0f;

    UPROPERTY(BlueprintReadOnly, Category = "Animation")
    bool bShouldRunning;

    UFUNCTION(BlueprintCallable, Category = "Animation")
    bool GetShouldRunning() const { return bShouldRunning; }

protected:
    virtual void BeginPlay() override;

    void Tick(float DeltaTime);
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    ULMAHealthComponent* HealthComponent;
};
