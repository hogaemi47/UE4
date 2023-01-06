// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPawn.h"
#include "MotioncontrollerComponent.h"
#include "Components/SceneComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AVRPawn::AVRPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VRTrackingCenter = CreateDefaultSubobject<USceneComponent>(TEXT("VRTrackingCenter"));
	VRCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("VRCameraComponent"));
	OutputText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("OutputText"));

	LeftController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("LeftController"));
	LeftController->SetTrackingSource(EControllerHand::Left);
	LeftSword = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftSword"));
	LeftHand = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("LeftHand"));

	RightController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("RightConterller"));
	RightController->SetTrackingSource(EControllerHand::Right);
	RightSword = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightSword"));
	RightHand = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("RightHand"));

	VRCameraComponent->SetupAttachment(VRTrackingCenter);
	OutputText->SetupAttachment(VRCameraComponent);

	LeftController->SetupAttachment(VRTrackingCenter);
	LeftHand->SetupAttachment(LeftController);
	LeftSword->SetupAttachment(LeftHand);

	RightController->SetupAttachment(VRTrackingCenter);
	RightHand->SetupAttachment(RightController);
	RightSword->SetupAttachment(RightHand);
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

