#pragma once

#include "CoreMinimal.h"
#include "Characters/WarriorCharacterBase.h"
#include "WarriorEnemyCharacter.generated.h"

class UWidgetComponent;
class UEnemyUIComponent;
class UEnemyCombatComponent;

UCLASS()
class WARRIOR_API AWarriorEnemyCharacter : public AWarriorCharacterBase
{
	GENERATED_BODY()

public :
	AWarriorEnemyCharacter();

	//~ Begin IPawnCombatInterface 
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
	//~ End IPawnCombatInterface

	//~ Begin IPawnUIInterface 
	virtual UPawnUIComponent* GetPawnUIComponent() override;
	virtual UEnemyUIComponent* GetEnemyUIComponent() const override;
	//~ End IPawnUIInterface 

	FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const { return EnemyCombatComponent; }

protected :
	virtual void PossessedBy(AController* NewController) override;
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	TObjectPtr<UEnemyCombatComponent> EnemyCombatComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
	TObjectPtr<UEnemyUIComponent> EnemyUIComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
	TObjectPtr<UWidgetComponent> EnemyHealthWidgetComponent;

private :
	void InitEnemyStartUpData();

};
