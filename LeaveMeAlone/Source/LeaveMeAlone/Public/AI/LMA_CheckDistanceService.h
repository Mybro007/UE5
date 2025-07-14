// LeaveMeAlone Game by Netologiya. All RightsReserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "LMA_CheckDistanceService.generated.h"

/**
 * 
 */
UCLASS()
class LEAVEMEALONE_API ULMACheckDistanceService : public UBTService_BlackboardBase
{
    GENERATED_BODY()

public:
    ULMACheckDistanceService();

protected:
    virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    float MaxDistance = 300.0f; // 3 метра в сантиметрах

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    float RunSpeed = 600.0f; // Скорость бега

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    float WalkSpeed = 300.0f; // Обычная скорость
};
