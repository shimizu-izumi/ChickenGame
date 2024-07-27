// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ChickenCollectible.h"
#include "CoinCollectible.generated.h"

UCLASS()
class CHICKENGAME_API ACoinCollectible : public AChickenCollectible
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACoinCollectible();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
