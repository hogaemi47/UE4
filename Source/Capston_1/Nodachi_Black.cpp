// Fill out your copyright notice in the Description page of Project Settings.


#include "Nodachi_Black.h"
#include "Components/BoxComponent.h"

ANodachi_Black::ANodachi_Black()
{
	//Find object and Get Overloap to Object
	static ConstructorHelpers::FObjectFinder<UStaticMesh> loadedObj(TEXT("/Game/Meshes/SamuraiWeapons/Meshes/Nodachi_Black.Nodachi_Black"));

	this->GetStaticMeshComponent()->SetStaticMesh(loadedObj.Object);

	this->GetStaticMeshComponent()->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));

	static ConstructorHelpers::FObjectFinder<UMaterial> loadedMat(TEXT("Material'/Game/Meshes/SamuraiWeapons/Materials/Katana_Black.Katana_Black'"));

	this->GetStaticMeshComponent()->SetMaterial(0, loadedMat.Object);
	this->GetStaticMeshComponent()->SetSimulatePhysics(true);
	this->SetMobility(EComponentMobility::Movable);

	this->GetStaticMeshComponent()->SetGenerateOverlapEvents(true);

	//Making Collsion Box
	SwordHitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collsion Box"));
}