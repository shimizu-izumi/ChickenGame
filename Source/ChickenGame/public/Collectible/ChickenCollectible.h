// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "ChickenCollectible.generated.h"

UCLASS(Abstract)
class CHICKENGAME_API AChickenCollectible : public APaperSpriteActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AChickenCollectible();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
