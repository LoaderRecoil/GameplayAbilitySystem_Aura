// Copyright LoaderRecoil


#include "AbilitySystem/Abilities/AuraFireBolt.h"
#include "Aura/Public/AuraGameplayTags.h"

FString UAuraFireBolt::GetDescription(int32 Level)
{
	const int32 Damage = GetDamageByDamageType(Level, FAuraGameplayTags::Get().Damage_Fire);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	if (Level == 1)
	{
		return FString::Printf(TEXT(
			//Title
			"<Title>FIRE BOLT</>\n\n"
			//Details
			"<Small>Level: </><Level>%d</>\n" /*Level*/
			"<Small>ManaCost: </><ManaCost>%.1f</>\n" /*ManaCost*/
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n" /*Cooldown*/
			//Description
			"<Default>Launches a bolt of fire, exploding on impact and dealing: </>"
			"<Damage>%d</>" /*Damage*/
			"<Default> fire damage with a chance to burn</>"), 
			// Values
			Level,
			ManaCost,
			Cooldown,
			Damage);
	}
	else
	{
		return FString::Printf(TEXT(
			//Title
			"<Title>FIRE BOLT</>\n\n"
			//Details
			"<Small>Level: </><Level>%d</>\n" /*Level*/
			"<Small>ManaCost: </><ManaCost>%.1f</>\n" /*ManaCost*/
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n" /*Cooldown*/
			//Description
			"<Default>Launches %d bolts of fire, exploding on impact and dealing: </>" /*NumProjectiles*/
			"<Damage>%d</>" /*Damage*/
			"<Default> fire damage with a chance to burn</>"),
			// Values
			Level,
			ManaCost,
			Cooldown,
			FMath::Min(Level, NumProjectiles),
			Damage);
	}
}

FString UAuraFireBolt::GetNextLevelDescription(int32 Level)
{
	const int32 Damage = GetDamageByDamageType(Level, FAuraGameplayTags::Get().Damage_Fire);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	return FString::Printf(TEXT(
		//Title
		"<Title>Next Level: </>\n\n"
		//Details
		"<Small>Level: </><Level>%d</>\n" /*Level*/
		"<Small>ManaCost: </><ManaCost>%.1f</>\n" /*ManaCost*/
		"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"/*Cooldown*/
		//Description
		"<Default>Launches %d bolts of fire, exploding on impact and dealing: </>" /*NumProjectiles*/
		"<Damage>%d</>" /*Damage*/
		"<Default> fire damage with a chance to burn</>"),
		// Values
		Level,
		ManaCost,
		Cooldown,
		FMath::Min(Level, NumProjectiles),
		Damage);
}