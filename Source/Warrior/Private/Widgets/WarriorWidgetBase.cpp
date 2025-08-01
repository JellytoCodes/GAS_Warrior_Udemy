
#include "Widgets/WarriorWidgetBase.h"

#include "Components/UI/EnemyUIComponent.h"
#include "Interfaces/PawnUIInterface.h"

void UWarriorWidgetBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (const IPawnUIInterface* PawnUIInterface = Cast<IPawnUIInterface>(GetOwningPlayerPawn()))
	{
		if (UHeroUIComponent* HeroUIComponent = PawnUIInterface->GetHeroUIComponent())
		{
			BP_OnOwningHeroUIComponentInitialized(HeroUIComponent);
		}
	}
}

void UWarriorWidgetBase::InitEnemyCreatedWidget(AActor* OwningEnemyActor)
{
	if (const IPawnUIInterface* PawnUIInterface = Cast<IPawnUIInterface>(OwningEnemyActor))
	{
		if (UEnemyUIComponent* EnemyUIComponent = PawnUIInterface->GetEnemyUIComponent())
		{
			checkf(EnemyUIComponent, TEXT("Failed to extract an EnemyUiComponent form %s"), *OwningEnemyActor->GetActorNameOrLabel());

			BP_OnOwningEnemyUIComponentInitialized(EnemyUIComponent);
		}
	}
}