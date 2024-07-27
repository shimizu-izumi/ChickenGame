// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectible/ChickenCollectible.h"

#include "PaperSpriteComponent.h"


// Sets default values
AChickenCollectible::AChickenCollectible()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	GetRenderComponent()->SetCollisionResponseToAllChannels(ECR_Overlap);
}

void AChickenCollectible::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	Destroy();
}
