// Copyright EmbracedIT Ltd
#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()
private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	int32 StartingHealth=100;

	UPROPERTY(VisibleAnywhere, Category = Health)
	int32 CurrentHealth = StartingHealth;

	// Sets default values for this pawn's properties
	ATank();
public:
	// Called by the engine when actor damage is dealt
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

	// Return current health as a percentage of starting health, between 0 and 1
	UFUNCTION(BlueprintPure)
	float GetHealthPercent() const;
};
