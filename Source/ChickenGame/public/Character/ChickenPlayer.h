// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"

#include "ChickenPlayer.generated.h"

class UPaperSpriteComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class CHICKENGAME_API AChickenPlayer : public APaperZDCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AChickenPlayer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USpringArmComponent* SpringArmComponent;
	
protected:
	virtual void Tick(float DeltaSeconds) override;
};
