// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UWarriorGameplayAbility;
class UWarriorAbilitySystemComponent;
class UGameplayEffect;
/**
 * 
 */
UCLASS()
class RPGCOMBAT_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()
public:
	virtual void GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InWarriorASCToGive, int32 ApplyLevel = 1); 
protected:
	UPROPERTY(EditDefaultsOnly, Category= "StartUpData")
	TArray<TSubclassOf<UWarriorGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category= "StartUpData")
	TArray<TSubclassOf<UWarriorGameplayAbility>> ReactiveAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray< TSubclassOf < UGameplayEffect > > StartUpGameplayEffects;
	
	void GrantAbilities(const TArray<TSubclassOf<UWarriorGameplayAbility>>& InAbilitiesToGive,
						UWarriorAbilitySystemComponent* InWarriorASCToGive,
						int32 Applylevel = 1);
};
