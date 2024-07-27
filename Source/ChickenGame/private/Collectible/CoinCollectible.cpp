// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectible/CoinCollectible.h"

#include "ChickenGameInstance.h"
#include "Character/ChickenPlayer.h"


// Sets default values
ACoinCollectible::ACoinCollectible()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ACoinCollectible::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (AChickenPlayer* Player = Cast<AChickenPlayer>(OtherActor))
	{
		if (UChickenGameInstance* GameInstance = Cast<UChickenGameInstance>(GetGameInstance()))
		{
			GameInstance->Coins++;
		}
	}
	
	Super::NotifyActorBeginOverlap(OtherActor);
}
