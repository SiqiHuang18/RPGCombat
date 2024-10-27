// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/Hero/WarrioHeroAnimInstance.h"

#include "RPGCombat/RPGCombatCharacter.h"

void UWarrioHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if(OwningCharacter)
	{
		OwningHeroCharacter = Cast<ARPGCombatCharacter>(OwningCharacter);
	}
}

void UWarrioHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if(bHasAcceleration)
	{
		IdleElapsedTime = 0.f;
		bShouldEnterRelaxState = false;
	}else
	{
		IdleElapsedTime += DeltaSeconds;
		bShouldEnterRelaxState = (IdleElapsedTime >= EnterRelaxStateThreshold);
	}
}
