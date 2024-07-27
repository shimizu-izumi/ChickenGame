// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Collectible/ChickenCollectible.h"
#include "ChestInteractable.generated.h"

class UWorld;

UCLASS()
class CHICKENGAME_API AChestInteractable : public APaperSpriteActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AChestInteractable();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Chest", meta = (AllowedTypes = "Map"))
	FPrimaryAssetId LevelToLoad;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
