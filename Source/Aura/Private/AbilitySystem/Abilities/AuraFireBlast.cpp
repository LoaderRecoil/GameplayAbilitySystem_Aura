// Copyright LoaderRecoil


#include "AbilitySystem/Abilities/AuraFireBlast.h"
#include "AbilitySystem/AuraAbilitySystemLibrary.h"
#include "Actor/AuraFireBall.h"

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

TArray<AAuraFireBall*> UAuraFireBlast::SpawnFireBalls()
{
	TArray<AAuraFireBall*> FireBalls;
	const FVector Forward = GetAvatarActorFromActorInfo()->GetActorForwardVector();
	const FVector Location = GetAvatarActorFromActorInfo()->GetActorLocation();
	TArray<FRotator> Rotators = UAuraAbilitySystemLibrary::EvenlySpacedRotators(Forward, FVector::UpVector, 360.0f, NumFireBalls);

	for (const FRotator& Rotator : Rotators)
	{
		FTransform SpawnTransform;
		SpawnTransform.SetLocation(Location);
		SpawnTransform.SetRotation(Rotator.Quaternion());

		AAuraFireBall* FireBall = GetWorld()->SpawnActorDeferred<AAuraFireBall>(
			FireBallClass, 
			SpawnTransform, 
			GetOwningActorFromActorInfo(),
			CurrentActorInfo->PlayerController->GetPawn(),
			ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

		FireBall->DamageEffectParams = MakeDamageEffectParamsFromClassDefaults();
		FireBall->ReturnToActor = GetAvatarActorFromActorInfo();

		FireBall->ExplosionDamageParams = MakeDamageEffectParamsFromClassDefaults();
		FireBall->SetOwner(GetAvatarActorFromActorInfo());

		FireBalls.Add(FireBall);

		FireBall->FinishSpawning(SpawnTransform);
	}

	return FireBalls;
}
