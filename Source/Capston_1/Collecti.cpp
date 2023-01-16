// Fill out your copyright notice in the Description page of Project Settings.


#include "Collecti.h"
#include "Components/BoxComponent.h"

ACollecti::ACollecti()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> loadedObj(TEXT("/Game/Meshes/SamuraiWeapons/Meshes/Nodachi_White.Nodachi_White"));

	this->GetStaticMeshComponent()->SetStaticMesh(loadedObj.Object);

	this->GetStaticMeshComponent()->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));

	static ConstructorHelpers::FObjectFinder<UMaterial> loadedMat(TEXT("Material'/Game/Meshes/SamuraiWeapons/Materials/Katana_White.Katana_White'"));

	this->GetStaticMeshComponent()->SetMaterial(0, loadedMat.Object);
	this->GetStaticMeshComponent()->SetSimulatePhysics(true);
	this->SetMobility(EComponentMobility::Movable);

	this->GetStaticMeshComponent()->SetGenerateOverlapEvents(true);

	SwordHitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collsion Box"));
}
