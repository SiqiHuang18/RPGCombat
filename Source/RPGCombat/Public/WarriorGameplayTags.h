// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NativeGameplayTags.h"
/**
 * 
 */
namespace WarriorGameplayTags
{
	/** Input Tags**/
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_MOVE);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_LOOK);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_EquipAxe);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnequipAxe);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_LightAttack_Axe);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_HeavyAttack_Axe);
	/** Player Tags**/
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Equip_Axe);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Unequip_Axe);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Light_Axe);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Heavy_Axe);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);

	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Axe);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_UnEquip_Axe);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Status_JumpToFinisher);
}

