// LeaveMeAlone Game by Netologiya. All RightsReserved.


#include "AI/LMA_CheckDistanceService.h"
#include "Enemy/LMAEnemyCharacter.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/LMADefaultCharacter.h"

ULMACheckDistanceService::ULMACheckDistanceService()
{
    NodeName = "Check Distance To Player";
    bNotifyBecomeRelevant = true;
    bNotifyCeaseRelevant = true;
}

void ULMACheckDistanceService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaTime)
{
    const auto Controller = OwnerComp.GetAIOwner();
    if (!Controller) return;

    const auto BBComp = OwnerComp.GetBlackboardComponent();
    if (!BBComp) return;

    const auto Pawn = Controller->GetPawn();
    if (!Pawn) return;

    const auto EnemyCharacter = Cast<ALMAEnemyCharacter>(Pawn);
    if (!EnemyCharacter) return;

    const auto Player = Cast<ALMADefaultCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
    if (!Player) return;

    const float Distance = FVector::Distance(Player->GetActorLocation(), Pawn->GetActorLocation());
    EnemyCharacter->bShouldRunning = (Distance > MaxDistance); // Устанавливаем значение

    // Меняем скорость движения
    if (auto MovementComponent = EnemyCharacter->GetCharacterMovement())
    {
        MovementComponent->MaxWalkSpeed = EnemyCharacter->bShouldRunning ? RunSpeed : WalkSpeed;
    }
}