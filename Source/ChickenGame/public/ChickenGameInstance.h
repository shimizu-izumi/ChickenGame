// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ChickenGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CHICKENGAME_API UChickenGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly)
	int32 Coins = 0;
};
