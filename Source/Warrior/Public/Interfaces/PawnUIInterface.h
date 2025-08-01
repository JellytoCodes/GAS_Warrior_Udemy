#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PawnUIInterface.generated.h"

class UEnemyUIComponent;
class UHeroUIComponent;
class UPawnUIComponent;

UINTERFACE(MinimalAPI)
class UPawnUIInterface : public UInterface
{
	GENERATED_BODY()
};

class WARRIOR_API IPawnUIInterface
{
	GENERATED_BODY()

public:
	virtual UPawnUIComponent* GetPawnUIComponent() = 0;

	virtual UHeroUIComponent* GetHeroUIComponent() const;
	virtual UEnemyUIComponent* GetEnemyUIComponent() const;
};
