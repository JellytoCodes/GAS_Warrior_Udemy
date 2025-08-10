
#include "Items/PickUps/WarriorStoneBase.h"
#include "WarriorGameplayTags.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "Characters/WarriorHeroCharacter.h"

void AWarriorStoneBase::Consume(UWarriorAbilitySystemComponent* WarriorASC, int32 ApplyLevel)
{
	check(StoneGameplayEffectClass);

	const UGameplayEffect* EffectCD0 = StoneGameplayEffectClass->GetDefaultObject<UGameplayEffect>();
	WarriorASC->ApplyGameplayEffectToSelf(EffectCD0, ApplyLevel, WarriorASC->MakeEffectContext());

	BP_OnStoneConsumed();
}

void AWarriorStoneBase::OnPickUpCollisionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AWarriorHeroCharacter* OverlappedHeroCharacter = Cast<AWarriorHeroCharacter>(OtherActor))
	{
		OverlappedHeroCharacter->GetWarriorAbilitySystemComponent()->TryActivateAbilityByTag(WarriorGameplayTags::Player_Ability_PickUp_Stones);
	}
}
