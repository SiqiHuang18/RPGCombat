// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorGameplayTags.h"

namespace WarriorGameplayTags
{
	UE_DEFINE_GAMEPLAY_TAG(InputTag_MOVE, "InputTag.Move")
	UE_DEFINE_GAMEPLAY_TAG(InputTag_LOOK, "InputTag.Look")
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe, "Player.Weapon.Axe")
	UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipAxe,"InputTag.Equip.Axe");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnequipAxe,"InputTag.Unequip.Axe");
	
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Equip_Axe,"Player.Ability.Equip.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Unequip_Axe,"Player.Ability.Unequip.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Equip_Axe,"Player.Event.Equip.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_UnEquip_Axe,"Player.Event.Unequip.Axe");
}
