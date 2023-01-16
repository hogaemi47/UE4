// Fill out your copyright notice in the Description page of Project Settings.


#include "Korean_Scabbard.h"
#include "Components/BoxComponent.h"

AKorean_Scabbard::AKorean_Scabbard()
{
	//Find object and Get Overloap to Object
	static ConstructorHelpers::FObjectFinder<UStaticMesh> loadedObj(TEXT("/Game/Kitsune/Mesh/SM_Kitsune_Katana_Scabbard.SM_Kitsune_Katana_Scabbard"));

	this->GetStaticMeshComponent()->SetStaticMesh(loadedObj.Object);

	this->GetStaticMeshComponent()->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));

	static ConstructorHelpers::FObjectFinder<UMaterial> loadedMat(TEXT("Material'/Game/Kitsune/Materials/M_Kitsune_Katana.M_Kitsune_Katana'"));

	this->GetStaticMeshComponent()->SetMaterial(0, loadedMat.Object);
	this->GetStaticMeshComponent()->SetSimulatePhysics(true);
	this->SetMobility(EComponentMobility::Movable);

	this->GetStaticMeshComponent()->SetGenerateOverlapEvents(true);

	//Making Collsion Box
	SwordHitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collsion Box"));
}
