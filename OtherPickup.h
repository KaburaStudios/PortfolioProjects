// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OtherItem.h"
#include "OtherPickup.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API AOtherPickup : public AOtherItem
{
	GENERATED_BODY()
public:

	AOtherPickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Coins")
	int32 CoinCount;

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
	
};
