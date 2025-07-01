// LeaveMeAlone Game by Netologiya. All RightsReserved.


#include "MyGameModeBase.h"
#include "Player/LMADefaultCharacter.h"
#include "Player/LMAPlayerController.h"

AMyGameModeBase::AMyGameModeBase()
{
	DefaultPawnClass = ALMADefaultCharacter::StaticClass();
	PlayerControllerClass = ALMAPlayerController::StaticClass();
}