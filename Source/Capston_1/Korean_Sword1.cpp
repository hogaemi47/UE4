// Fill out your copyright notice in the Description page of Project Settings.


#include "Korean_Sword1.h"
#include "Components/BoxComponent.h"

AKorean_Sword1::AKorean_Sword1()
{
	//Find object and Get Overloap to Object
	static ConstructorHelpers::FObjectFinder<UStaticMesh> loadedObj(TEXT("/Game/Kitsune/Mesh/SM_Kitsune_Katana_Sword1.SM_Kitsune_Katana_Sword1"));

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
