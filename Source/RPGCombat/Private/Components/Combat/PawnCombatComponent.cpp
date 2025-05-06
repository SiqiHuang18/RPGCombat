// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/PawnCombatComponent.h"
#include "Components/BoxComponent.h"
#include "Items/Weapons/WarriorWeaponBase.h"
#include "WarriorDebugHelper.h"
void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister,
                                                 AWarriorWeaponBase* InWeaponToRegister, bool bRegisteredAsEquippedWeapon)
{
	checkf(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister),TEXT("A name named %s has been added"),*InWeaponTagToRegister.ToString() )
	CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister, InWeaponToRegister);

	if(bRegisteredAsEquippedWeapon)
	{
		CurrentEquippedWeaponTag = InWeaponTagToRegister;
	}

	InWeaponToRegister->OnWeaponHitTarget.BindUObject(this,&ThisClass::OnHitTargetActor);
	InWeaponToRegister->OnWeaponPulledFromTarget.BindUObject(this,&ThisClass::OnWeaponPulledFromTargetActor);
	
	const FString WeaponString = FString::Printf(TEXT("a weapon named %s has been registered using tag %s"),*InWeaponToRegister->GetName(),*InWeaponTagToRegister.ToString());
	Debug::Print((WeaponString));
}

AWarriorWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
	if (CharacterCarriedWeaponMap.Contains(InWeaponTagToGet))
	{
		if(AWarriorWeaponBase* const* FoundWeapon = CharacterCarriedWeaponMap.Find(InWeaponTagToGet))
		{
			return *FoundWeapon;
		}
	}
	return nullptr;
}

AWarriorWeaponBase* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	if(!CurrentEquippedWeaponTag.IsValid())
	{
		return nullptr;
	}

	return GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}

void UPawnCombatComponent::ToggleWeaponCollision(bool bShouldEnable, EToggleDamageType ToggleDamageType)
{
	if (ToggleDamageType == EToggleDamageType::CurrentEquippedWeapon)
	{
		AWarriorWeaponBase* WeaponToToggle = GetCharacterCurrentEquippedWeapon();
 
		check(WeaponToToggle);
 
		if (bShouldEnable)
		{
			WeaponToToggle->GetWeaponCollisionBox()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		}
		else
		{
			WeaponToToggle->GetWeaponCollisionBox()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			OverlappedActors.Empty();
		}		
	}
}

void UPawnCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	//Debug::Print(GetOwningPawn()->GetActorNameOrLabel() + TEXT(" hit ") + HitActor->GetActorNameOrLabel(),FColor::Green);
}

void UPawnCombatComponent::OnWeaponPulledFromTargetActor(AActor* InteractedActor)
{
	//Debug::Print(GetOwningPawn()->GetActorNameOrLabel() + TEXT("'s weapon pulled from ") + InteractedActor->GetActorNameOrLabel(),FColor::Red);
}
