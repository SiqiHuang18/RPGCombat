// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarriorBaseAnimInstance.h"
#include "WarrioCharacterAnimInstance.generated.h"
class UCharacterMovementComponent;
class ARPGCombatCharacter;

/**
 * 
 */
UCLASS()
class RPGCOMBAT_API UWarrioCharacterAnimInstance : public UWarriorBaseAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY()
	ARPGCombatCharacter* OwningCharacter;

	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComponent;

	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly,Category = "AnimData|LocomotionData")
	float GroundSpeed;
	
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly,Category = "AnimData|LocomotionData")
	bool bHasAcceleration;
};
