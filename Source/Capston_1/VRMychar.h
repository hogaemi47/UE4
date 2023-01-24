// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/TextRenderComponent.h"
#include "MotionControllerComponent.h"
#include "GameFramework/Character.h"
#include "VRMychar.generated.h"

UCLASS()
class CAPSTON_1_API AVRMychar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVRMychar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

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

	//다음 레벨로 이동하기 위한 방법
	bool Right_has_sword;
	bool Left_has_sword;

	//왼손 오른손 칼잡기
	void GrabRightPressed();
	void GrabLeftPressed();

	//VRPawn Movement
	void MoveForward(float AxisValue);
	void MoveRight(float AixsValue);
};
