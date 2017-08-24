// Copyright EmbracedIT Ltd

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming state
UENUM()
enum class EAimingState :uint8
{
	Reloading,
	Aiming,
	Locked,
	OutOfAmmo
};

class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Fire();

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	int GetRoundsLeft() const;

	EAimingState GetAimingState();
protected:
	UPROPERTY(BlueprintReadOnly)
	EAimingState AimingState = EAimingState::Reloading;

private:
	// Sets default values for this component's properties
	UTankAimingComponent();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint; //Alternative https://docs.unrealengine.com/latest/KOR/Programming/UnrealArchitecture/TSubclassOf/index.html


	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	int32 RoundsLeft = 3;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float ReloadTimeInSeconds = 6.7f;
	double LastFireTime = 0;

	FVector AimDirection;

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards();

	bool isBarrelMoving();
};
