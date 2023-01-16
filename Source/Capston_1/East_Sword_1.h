// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/Material.h"
#include "VRPawn.h"
#include "Engine/StaticMesh.h"
#include "East_Sword_1.generated.h"

/**
 * 
 */
UCLASS()
class CAPSTON_1_API AEast_Sword_1 : public AStaticMeshActor
{
	GENERATED_BODY()

	AEast_Sword_1();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Collision_Box)
	class UBoxComponent* SwordHitBox;
	
};
