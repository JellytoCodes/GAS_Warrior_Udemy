#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "GameFramework/PlayerController.h"
#include "WarriorHeroController.generated.h"

UCLASS()
class WARRIOR_API AWarriorHeroController : public APlayerController, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public :
	AWarriorHeroController();

	//~ Begin IGenericTeamAgentInterface
	virtual FGenericTeamId GetGenericTeamId() const override;
	//~ End IGenericTeamAgentInterface

private :
	FGenericTeamId HeroTeamID;
};
