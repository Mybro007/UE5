// LeaveMeAlone Game by Netologiya. All RightsReserved.


#include "Enemy/LMAEnemyCharacter.h"

// Sets default values
ALMAEnemyCharacter::ALMAEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	HealthComponent = CreateDefaultSubobject<ULMAHealthComponent>("HealthComponent");
}

// Called when the game starts or when spawned
void ALMAEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALMAEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


