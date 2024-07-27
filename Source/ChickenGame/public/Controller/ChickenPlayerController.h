// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "ChickenPlayerController.generated.h"

class UInputAction;
struct FInputActionValue;
class UInputMappingContext;
/**
 * 
 */
UCLASS()
class CHICKENGAME_API AChickenPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	//~ Begin APlayerController Interface
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	//~ End APlayerController Interface

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> MappingContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;

	void PlayerMove(const FInputActionValue& Value);
	void PlayerJump();
};
