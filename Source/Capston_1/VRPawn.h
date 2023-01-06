// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "Components/TextRenderComponent.h"
#include "MotionControllerComponent.h"
#include "VRPawn.generated.h"

UCLASS()
class CAPSTON_1_API AVRPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AVRPawn();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Setting VR
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = __hide)
	USceneComponent* VRTrackingCenter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = __hide)
	UCameraComponent* VRCameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = __hide)
	UTextRenderComponent* OutputText;

	//MotionControllerComponent
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = __hide)
	UMotionControllerComponent* LeftController;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = __hide)
	UMotionControllerComponent* RightController;

	//StaticMeshComponent
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = __hide)
	UStaticMeshComponent* LeftSword;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = __hide)
	USkeletalMeshComponent* LeftHand;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = __hide)
	UStaticMeshComponent* RightSword;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = __hide)
	USkeletalMeshComponent* RightHand;
};
