// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Aghanim_RPGCharacter.generated.h"

UCLASS(config = Game)
class AAghanim_RPGCharacter : public ACharacter
{
	GENERATED_BODY()

		/** Camera boom positioning the camera behind the character */
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;
public:
	AAghanim_RPGCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input)
		float TurnRateGamepad;

protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		bool canLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int xp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int xpToLevelUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int upgradePoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int strength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int agility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int intelligence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float mana;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float maxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float maxMana;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float armor;

protected:



	/*
	UFUNCTION(BlueprintCallable, Category = "Health")
		void takeDamage(float damageAmount);

	UFUNCTION(BlueprintCallable, Category = "Health")
		void heal(float healAmount);
		*/
	UFUNCTION(BlueprintCallable, Category = "Stats")
		void dealDamage();

	UFUNCTION(BlueprintCallable, Category = "Health")
		void sprint();

	UFUNCTION(BlueprintCallable, Category = "Health")
		void stopSprint();

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void onLevelUp();

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void addStatStrength();

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void addStatAgility();

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void addStatIntelligence();


	UFUNCTION(BlueprintCallable, Category = "Stats")
		void calculateStats();




	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
