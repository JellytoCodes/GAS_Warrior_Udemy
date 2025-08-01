#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Characters/WarriorCharacterBase.h"
#include "WarriorHeroCharacter.generated.h"

class UHeroUIComponent;
class UHeroCombatComponent;
struct FInputActionValue;

class UDataAsset_InputConfig;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class WARRIOR_API AWarriorHeroCharacter : public AWarriorCharacterBase
{
	GENERATED_BODY()

public :
	AWarriorHeroCharacter();

	//~ Begin IPawnCombatInterface 
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
	//~ End IPawnCombatInterface 

	//~ Begin IPawnUIInterface 
	virtual UPawnUIComponent* GetPawnUIComponent() override;
	virtual UHeroUIComponent* GetHeroUIComponent() const override;
	//~ End IPawnUIInterface 

	FORCEINLINE UHeroCombatComponent* GetHeroCombatComponent() const { return HeroCombatComponent; }

protected :
	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private :
#pragma region Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UHeroCombatComponent> HeroCombatComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UHeroUIComponent> HeroUIComponent;
#pragma endregion

#pragma region Inputs
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UDataAsset_InputConfig> InputConfigDataAsset;

	void Input_Move(const FInputActionValue& InputActionValue);
	void Input_Look(const FInputActionValue& InputActionValue);

	void Input_AbilityInputPressed(FGameplayTag InInputTag);
	void Input_AbilityInputReleased(FGameplayTag InInputTag);
#pragma endregion
};
