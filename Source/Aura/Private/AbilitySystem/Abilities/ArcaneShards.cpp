// Copyright LoaderRecoil


#include "AbilitySystem/Abilities/ArcaneShards.h"

FString UArcaneShards::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	if (Level == 1)
	{
		return FString::Printf(TEXT(
			//Title
			"<Title>ARCANE SHARDS</>\n\n"
			//Details
			"<Small>Level: </><Level>%d</>\n" /*Level*/
			"<Small>ManaCost: </><ManaCost>%.1f</>\n" /*ManaCost*/
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n" /*Cooldown*/
			//Description
			"<Default>Summon a shard of arcane energy, causing </>"
			"<Damage>%d</>" /*Damage*/
			"<Default> radial arcane damage at the shard origin.</>"),
			// Values
			Level,
			ManaCost,
			Cooldown,
			ScaledDamage);
	}
	else
	{
		return FString::Printf(TEXT(
			//Title
			"<Title>ARCANE SHARDS</>\n\n"
			//Details
			"<Small>Level: </><Level>%d</>\n" /*Level*/
			"<Small>ManaCost: </><ManaCost>%.1f</>\n" /*ManaCost*/
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n" /*Cooldown*/
			//Description
			"<Default>Summon %d shards of arcane energy, causing </>" /*MaxNumShockTargets*/
			"<Damage>%d</>" /*Damage*/
			"<Default> radial arcane damage at the shard origins.</>"),
			// Values
			Level,
			ManaCost,
			Cooldown,
			FMath::Min(Level, MaxNumShards),
			ScaledDamage);
	}
}

FString UArcaneShards::GetNextLevelDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	return FString::Printf(TEXT(
		//Title
		"<Title>NEXT LEVEL: </>\n\n"
		//Details
		"<Small>Level: </><Level>%d</>\n" /*Level*/
		"<Small>ManaCost: </><ManaCost>%.1f</>\n" /*ManaCost*/
		"<Small>Cooldown: </><Cooldown>%.1f</>\n\n" /*Cooldown*/
		//Description
		"<Default>Summon %d shards of arcane energy, causing </>" /*MaxNumShockTargets*/
		"<Damage>%d</>" /*Damage*/
		"<Default> radial arcane damage at the shard origins.</>"),
		// Values
		Level,
		ManaCost,
		Cooldown,
		FMath::Min(Level, MaxNumShards),
		ScaledDamage);
}
