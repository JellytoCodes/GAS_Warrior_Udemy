#pragma once

#include "CoreMinimal.h"
#include "AnimInstance/WarriorAnimInstance.h"
#include "WarriorCharacterAnimInstance.generated.h"

class UCharacterMovementComponent;
class AWarriorCharacterBase;

UCLASS()
class WARRIOR_API UWarriorCharacterAnimInstance : public UWarriorAnimInstance
{
	GENERATED_BODY()

public :
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected :
	UPROPERTY()
	TObjectPtr<AWarriorCharacterBase> OwningCharacter;

	UPROPERTY()
	TObjectPtr<UCharacterMovementComponent> OwningMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bHasAcceleration;
};
