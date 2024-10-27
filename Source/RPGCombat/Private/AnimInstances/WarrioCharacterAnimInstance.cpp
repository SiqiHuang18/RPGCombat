// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/WarrioCharacterAnimInstance.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "RPGCombat/RPGCombatCharacter.h"

void UWarrioCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<ARPGCombatCharacter>(TryGetPawnOwner());
	if(OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void UWarrioCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if(!OwningCharacter || !OwningMovementComponent)
	{
		return;
	}

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();

	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;
}
