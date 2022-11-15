// Fill out your copyright notice in the Description page of Project Settings.


#include "OtherExplosive.h"
#include "MainUltimate.h"

AOtherExplosive::AOtherExplosive()
{
	Damage = 15.f;
}

void AOtherExplosive::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	UE_LOG(LogTemp, Warning, TEXT("OtherExplosive::OnOverlapBegin()"));

	if (OtherActor)
	{
		AMainUltimate* MainUltimate = Cast<AMainUltimate>(OtherActor);
		if (MainUltimate)
		{
			MainUltimate->DecrementHealth(Damage);

			Destroy();
		}
	}
}

void AOtherExplosive::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

	UE_LOG(LogTemp, Warning, TEXT("OtherExplosive::OnOverlapEnd()"));
}

