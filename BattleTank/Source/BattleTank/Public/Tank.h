// Copyright EmbracedIT Ltd
#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Fire();
	
private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// TODO remove once firing is moved to aiming component 
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint; //Alternative https://docs.unrealengine.com/latest/KOR/Programming/UnrealArchitecture/TSubclassOf/index.html

	UTankBarrel* Barrel = nullptr;

	float ReloadTimeInSeconds = 6.7f;
	double LastFireTime = 0;
};
