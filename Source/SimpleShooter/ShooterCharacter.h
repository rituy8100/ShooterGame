// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class AGun;

UCLASS()
class SIMPLESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintPure)	//you can call this at blueprint for get damage and die
		bool isDead() const;

	UFUNCTION(BlueprintPure)	//you can call this at blueprint for get damage and die
		float GetHEalthPercent() const;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser);
	void Shoot();


private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	/*void LookUp(float AxisValue);*/
	


	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AGun> GunClass;	//blueprint to choose AGun subclasses

	UPROPERTY(EditDefaultsOnly)
		float MaxHealth = 100;

	UPROPERTY(VisibleAnywhere)
		float Health;

	UPROPERTY()
		AGun* Gun;
};
