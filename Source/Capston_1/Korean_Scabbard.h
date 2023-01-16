// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/Material.h"
#include "VRPawn.h"
#include "Engine/StaticMesh.h"
#include "Korean_Scabbard.generated.h"

/**
 * 
 */
UCLASS()
class CAPSTON_1_API AKorean_Scabbard : public AStaticMeshActor
{
	GENERATED_BODY()

	AKorean_Scabbard();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Collision_Box)
	class UBoxComponent* SwordHitBox;
};
