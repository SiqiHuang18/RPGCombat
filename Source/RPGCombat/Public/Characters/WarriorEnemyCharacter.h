// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/WarriorBaseCharacter.h"
#include "WarriorEnemyCharacter.generated.h"

class UEnemyCombatComponent;
/**
 * 
 */
UCLASS()
class RPGCOMBAT_API AWarriorEnemyCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()

public:
	AWarriorEnemyCharacter();


	virtual void PossessedBy(AController* NewController) override;

	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
	
	FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const	{return EnemyCombatComponent;}
	
private:
	void InitEnemyStartUpData();
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Combat)
	UEnemyCombatComponent* EnemyCombatComponent;
};
