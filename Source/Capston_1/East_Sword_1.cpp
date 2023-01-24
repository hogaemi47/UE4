// Fill out your copyright notice in the Description page of Project Settings.


#include "East_Sword_1.h"
#include "Components/BoxComponent.h"

AEast_Sword_1::AEast_Sword_1()
{
	//Find object and Get Overloap to Object
	static ConstructorHelpers::FObjectFinder<UStaticMesh> loadedObj(TEXT("/Game/Meshes/Weapon_Pack/Mesh/Weapons/Weapons_Kit/SM_Sword.SM_Sword"));

	this->GetStaticMeshComponent()->SetStaticMesh(loadedObj.Object);

	this->GetStaticMeshComponent()->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));

	this->GetStaticMeshComponent()->SetSimulatePhysics(true);
	this->SetMobility(EComponentMobility::Movable);

	this->GetStaticMeshComponent()->SetGenerateOverlapEvents(true);

	//Making Collsion Box
	SwordHitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collsion Box"));
	RootComponent = SwordHitBox;
	SwordHitBox->SetCollisionProfileName(TEXT("OverlapPawn"));
}