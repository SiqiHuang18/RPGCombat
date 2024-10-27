// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarrioCharacterAnimInstance.h"
#include "WarrioHeroAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class RPGCOMBAT_API UWarrioHeroAnimInstance : public UWarrioCharacterAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
protected:
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly,Category = "AnimData|References")
	ARPGCombatCharacter* OwningHeroCharacter;
	
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly,Category = "AnimData|LocomotionData")
	bool bShouldEnterRelaxState;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "AnimData|LocomotionData")
	float EnterRelaxStateThreshold = 5.f;

	float IdleElapsedTime = 0.f;
};
