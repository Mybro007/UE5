// LeaveMeAlone Game by Netologiya. All RightsReserved.


#include "Enemy/LMAAIController.h"
#include "Enemy/LMAEnemyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

void ALMAAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    const auto AICharacter = Cast<ALMAEnemyCharacter>(InPawn);
    if (AICharacter)
    {
        RunBehaviorTree(AICharacter->BehaviorTreeAsset);

        // Используем другое имя переменной, чтобы избежать конфликта
        if (auto BBComponent = GetBlackboardComponent())
        {
            // Инициализируем значения по умолчанию
            BBComponent->SetValueAsBool("ShouldRun", false);
        }
    }
}