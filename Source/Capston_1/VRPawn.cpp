// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPawn.h"

// Sets default values
AVRPawn::AVRPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VRTrackingCenter = CreateDefaultSubobject<USceneComponent>(TEXT("VRTrackingCenter"));
	VRCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("VRCameraComponent"));
	OutputText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("OutputText"));

	LeftController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("LeftController"));
	LeftSword = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftSword"));
	LeftCone = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftCone"));
	
	RightController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("RightConterller"));
	RightSword = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightSword"));
	RightCone = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightCone"));
}

// Called when the game starts or when spawned
void AVRPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVRPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

