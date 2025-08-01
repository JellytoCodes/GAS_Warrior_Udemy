
#include "Characters/WarriorCharacterBase.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/WarriorAttributeSet.h"

AWarriorCharacterBase::AWarriorCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	WarriorAbilitySystemComponent = CreateDefaultSubobject<UWarriorAbilitySystemComponent>("WarriorAbilitySystemComponent");

	WarriorAttributeSet = CreateDefaultSubobject<UWarriorAttributeSet>("WarriorAttributeSet");
}

UAbilitySystemComponent* AWarriorCharacterBase::GetAbilitySystemComponent() const
{
	return GetWarriorAbilitySystemComponent();
}

UPawnCombatComponent* AWarriorCharacterBase::GetPawnCombatComponent() const
{
	return nullptr;
}

UPawnUIComponent* AWarriorCharacterBase::GetPawnUIComponent()
{
	return nullptr;
}

void AWarriorCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (WarriorAbilitySystemComponent)
	{
		WarriorAbilitySystemComponent->InitAbilityActorInfo(this, this);

		ensureMsgf(!CharacterStartUpData.IsNull(), TEXT("Forgot to assign start up data to %s"), *GetName());
	}
}

