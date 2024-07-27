// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ChickenPlayer.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
AChickenPlayer::AChickenPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->bDoCollisionTest = false;
	SpringArmComponent->SetUsingAbsoluteRotation(true);
	SpringArmComponent->SetWorldRotation(FRotator(0.f, -90.f, 0.f));

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	CameraComponent->ProjectionMode = ECameraProjectionMode::Orthographic;
	CameraComponent->OrthoWidth = 1280.f;
	
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->SetPlaneConstraintAxisSetting(EPlaneConstraintAxisSetting::Y);
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	GetCharacterMovement()->bUseFlatBaseForFloorChecks = true;
}

void AChickenPlayer::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (GetCharacterMovement()->Velocity.X > 0)
	{
		GetController()->SetControlRotation(FRotator(0.f, 180.f, 0.f));
	}
	else
	{
		GetController()->SetControlRotation(FRotator(0.f, 0.f, 0.f));
	}
}
