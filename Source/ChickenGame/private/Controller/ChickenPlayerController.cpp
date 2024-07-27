// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/ChickenPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"

void AChickenPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::PlayerMove);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ThisClass::PlayerJump);
}

void AChickenPlayerController::PlayerMove(const FInputActionValue& Value)
{
	float ScaleValue = Value.Get<float>();

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(FVector(1.0f, 0.0f, 0.0f), ScaleValue);
	}
}

void AChickenPlayerController::PlayerJump()
{
	if (ACharacter* ControlledPawn = GetPawn<ACharacter>())
	{
		ControlledPawn->Jump();
	}
}

void AChickenPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(MappingContext)

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(MappingContext, 0);
	}
}
