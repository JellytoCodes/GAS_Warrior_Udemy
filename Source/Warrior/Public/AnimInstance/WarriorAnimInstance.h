// All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Animation/AnimInstance.h"
#include "WarriorAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected :
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	bool DoesOwnerHaveTag(FGameplayTag TagToCheck) const;
};
