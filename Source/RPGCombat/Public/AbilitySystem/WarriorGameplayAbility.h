// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "WarriorGameplayAbility.generated.h"

UENUM(BlueprintType)
enum class EWarriorAbilityActivisionPolicy : uint8
{
	OnTriggered,
	OnGiven
};
/**
 * 
 */
UCLASS()
class RPGCOMBAT_API UWarriorGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
protected:

	//~Begin UGameplayAbility Interface
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	/** Native function, called if an ability ends normally or abnormally. If bReplicate is set to true, try to replicate the ending to the client/server */
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

	//~End UGameplayAbility Interface
	UPROPERTY(EditDefaultsOnly,Category= "WarriorAbility")
	EWarriorAbilityActivisionPolicy AbilityActivisionPolicy = EWarriorAbilityActivisionPolicy::OnTriggered;
	
};
