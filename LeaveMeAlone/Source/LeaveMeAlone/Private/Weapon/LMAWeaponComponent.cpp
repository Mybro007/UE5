// LeaveMeAlone Game by Netologiya. All RightsReserved.


#include "Weapon/LMAWeaponComponent.h"


// Sets default values for this component's properties
ULMAWeaponComponent::ULMAWeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULMAWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	SpawnWeapon();
	InitAnimNotify();
	// ...
	
}


// Called every frame
void ULMAWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void ULMAWeaponComponent::SpawnWeapon()
{
	Weapon = GetWorld()->SpawnActor<ALMABaseWeapon>(WeaponClass);
	if (Weapon)
	{
		const auto Character = Cast<ACharacter>(GetOwner());
		if (Character)
		{
			FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);
			Weapon->AttachToComponent(Character->GetMesh(), AttachmentRules, "r_Weapon_Socket");

			// ������������� �� ������� ����������� ������
			Weapon->OnClipEmpty.AddUObject(this, &ULMAWeaponComponent::OnClipEmpty);
		}
	}
}

void ULMAWeaponComponent::Fire()
{
	if (Weapon && !AnimReloading)
	{
		Weapon->Fire();
	}
}

void ULMAWeaponComponent::InitAnimNotify()
{
	if (!ReloadMontage)return;
	const auto NotifiesEvents = ReloadMontage->Notifies;
	for (auto NotifyEvent : NotifiesEvents)
	{
		auto ReloadFinish = Cast<ULMAReloadFinishedAnimNotify>(NotifyEvent.Notify);
		if (ReloadFinish)
		{
			ReloadFinish->OnNotifyReloadFinished.AddUObject(this, &ULMAWeaponComponent::OnNotifyReloadFinished);
			break;
		}
	}
}

void ULMAWeaponComponent::OnNotifyReloadFinished(USkeletalMeshComponent* SkeletalMesh)
{
	const auto Character = Cast<ACharacter>(GetOwner());
	if (Character->GetMesh() == SkeletalMesh)
	{
		AnimReloading = false;
	}
}

bool ULMAWeaponComponent::CanReload() const
{
	bool bCanReload = !AnimReloading && Weapon && !Weapon->IsClipFull();
	UE_LOG(LogTemp, Warning, TEXT("CanReload: %d (AnimReloading: %d, IsClipFull: %d)"),
		bCanReload, AnimReloading, Weapon ? Weapon->IsClipFull() : false);
	return !AnimReloading && Weapon && !Weapon->IsClipFull();
}

void ULMAWeaponComponent::Reload()
{
	UE_LOG(LogTemp, Warning, TEXT("Reload called!"));
	// �������� ����� ������� �����������
	StartReload();
}

void ULMAWeaponComponent::StopFire()
{
	if (Weapon)
	{
		Weapon->StopFire();
	}
}

void ULMAWeaponComponent::StartReload()
{
	if (!CanReload()) return;

	Weapon->ChangeClip();
	AnimReloading = true;
	ACharacter* Character = Cast<ACharacter>(GetOwner());
	if (Character && ReloadMontage)
	{
		Character->PlayAnimMontage(ReloadMontage);
	}
}

void ULMAWeaponComponent::OnClipEmpty()
{
	// �������������� ����������� ��� ����������� ������
	StartReload();
}