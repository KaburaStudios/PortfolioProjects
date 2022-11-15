// Fill out your copyright notice in the Description page of Project Settings.


#include "OtherEnemyAnimInstance.h"
#include "OtherEnemy.h"


void UOtherEnemyAnimInstance::NativeInitializeAnimation()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
		if (Pawn)
		{
			OtherEnemy = Cast<AOtherEnemy>(Pawn);
		}
	}
}


void UOtherEnemyAnimInstance::UpdateAnimationProperties()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
		if (Pawn)
		{
			OtherEnemy = Cast<AOtherEnemy>(Pawn);
		}
	}

	if (Pawn)
	{
		FVector Speed = Pawn->GetVelocity();
		FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.f);
		MovementSpeed = LateralSpeed.Size();
	}
}

