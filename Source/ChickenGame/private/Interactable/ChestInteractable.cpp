// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable/ChestInteractable.h"

#include "Character/ChickenPlayer.h"
#include "Engine/AssetManager.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AChestInteractable::AChestInteractable()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void AChestInteractable::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	
	if (AChickenPlayer* Player = CastChecked<AChickenPlayer>(OtherActor))
	{
		if (FAssetData WorldAssetData; UAssetManager::Get().GetPrimaryAssetData(LevelToLoad, WorldAssetData))
		{
			UGameplayStatics::OpenLevel(this,  WorldAssetData.AssetName);
		}
	}
}
