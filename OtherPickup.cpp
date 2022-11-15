// Fill out your copyright notice in the Description page of Project Settings.


#include "OtherPickup.h"
#include "MainUltimate.h"

AOtherPickup::AOtherPickup()
{
	CoinCount = 1;
}

void AOtherPickup::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	UE_LOG(LogTemp, Warning, TEXT("OtherPickup::OnOverlapBegin()"));

	if (OtherActor)
	{
		AMainUltimate* MainUltimate = Cast<AMainUltimate>(OtherActor);
		if (MainUltimate)
		{
			MainUltimate->IncrementCoins(CoinCount);
			MainUltimate->PickupLocations.Add(GetActorLocation());

			Destroy();
		}
	}
}

void AOtherPickup::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

	UE_LOG(LogTemp, Warning, TEXT("OtherPickup::OnOverlapEnd()"));
}

