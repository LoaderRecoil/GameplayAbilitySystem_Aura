// Copyright LoaderRecoil


#include "AbilitySystem/Abilities/AuraFireBlast.h"

FString UAuraFireBlast::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);

	return FString::Printf(TEXT(
		//Title
		"<Title>FIRE BLAST</>\n\n"
		//Details
		"<Small>Level: </><Level>%d</>\n" /*Level*/
		"<Small>ManaCost: </><ManaCost>%.1f</>\n" /*ManaCost*/
		"<Small>Cooldown: </><Cooldown>%.1f</>\n\n" /*Cooldown*/
		//Description
		"<Default>Launches </>"
		"<Default>%d</>" /*NumFireBalls*/
		"<Default> fire balls in all directions, each coming back and </>"
		"<Default>exploding upon retrun, causing </>"
		// Damage
		"<Damage>%d</>" /*ScaledDamage*/
		"<Default> radial fire damage with a chance to burn.</>"),
		// Values
		Level,
		ManaCost,
		Cooldown,
		NumFireBalls,
		ScaledDamage);
}

FString UAuraFireBlast::GetNextLevelDescription(int32 Level)
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
		"<Default>Launches </>"
		"<Default>%d</>" /*NumFireBalls*/
		"<Default> fire balls in all directions, each coming back and </>"
		"<Default>exploding upon retrun, causing </>"
		// Damage
		"<Damage>%d</>" /*ScaledDamage*/
		"<Default> radial fire damage with a chance to burn.</>"),
		// Values
		Level,
		ManaCost,
		Cooldown,
		NumFireBalls,
		ScaledDamage);
}
