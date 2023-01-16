// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/Material.h"
#include "VRPawn.h"
#include "Engine/StaticMesh.h"
#include "Nodachi_Black.generated.h"

/**
 * 
 */
UCLASS()
class CAPSTON_1_API ANodachi_Black : public AStaticMeshActor
{
	GENERATED_BODY()

	ANodachi_Black();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Collision_Box)
	class UBoxComponent* SwordHitBox;
};
