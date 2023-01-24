// Fill out your copyright notice in the Description page of Project Settings.


#include "VRMychar.h"
#include "Collecti.h"
#include "Nodachi_Black.h"
#include "Korean_Sword1.h"
#include "East_Sword_1.h"
#include "Korean_Scabbard.h"
#include "GameFrameWork/Pawn.h"
#include "MotioncontrollerComponent.h"
#include "Components/SceneComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "XRMotionControllerBase.h"

// Sets default values
AVRMychar::AVRMychar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//가장 상단이 되는 부분
	VRTrackingCenter = CreateDefaultSubobject<USceneComponent>(TEXT("VRTrackingCenter"));
	VRCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("VRCameraComponent"));
	OutputText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("OutputText"));

	//좌측 컨트롤러 세팅
	LeftController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("LeftController"));
	LeftController->SetTrackingSource(EControllerHand::Left);
	LeftSword = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftSword"));
	LeftHand = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("LeftHand"));

	//우측 컨트롤러 세팅
	RightController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("RightConterller"));
	RightController->SetTrackingSource(EControllerHand::Right);
	RightSword = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightSword"));
	RightHand = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("RightHand"));

	//상단이 되는 부분에 카메라 세팅
	VRCameraComponent->SetupAttachment(VRTrackingCenter);
	OutputText->SetupAttachment(VRCameraComponent);

	//좌측에 해당하는 Component들을 상속시켜주는 과정
	LeftController->SetupAttachment(VRTrackingCenter);
	LeftHand->SetupAttachment(LeftController);
	LeftSword->SetupAttachment(LeftHand);

	//우측에 해당하는 Component들을 상속시켜주는 과정
	RightController->SetupAttachment(VRTrackingCenter);
	RightHand->SetupAttachment(RightController);
	RightSword->SetupAttachment(RightHand);

	RightController->MotionSource = FXRMotionControllerBase::RightHandSourceId;
	LeftController->MotionSource = FXRMotionControllerBase::LeftHandSourceId;

	RightSword->SetRelativeLocation(FVector(15, 0, 0));
	LeftSword->SetRelativeLocation(FVector(15, 0, 0));

	this->RootComponent = VRTrackingCenter;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	static ConstructorHelpers::FObjectFinder<UMaterial> unlitText(TEXT("Material'/Engine/EngineMaterials/DefaultTextMaterialOpaque.DefaultTextMaterialOpaque'"));
	OutputText->SetMaterial(0, unlitText.Object);
	OutputText->SetTextRenderColor(FColor::Red);
	OutputText->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	OutputText->VerticalAlignment = EVerticalTextAligment::EVRTA_TextCenter;
	OutputText->SetRelativeRotation(FRotator(0, 180.0f, 0));
	OutputText->SetRelativeLocation(FVector(150, 0, 0));

	//Setting Collision to Sword meshes
	LeftSword->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	RightSword->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	//Overlap이 돼야함
	LeftSword->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	RightSword->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
}

// Called when the game starts or when spawned
void AVRMychar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVRMychar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVRMychar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("GrabRight", IE_Pressed, this, &AVRMychar::GrabRightPressed);
	PlayerInputComponent->BindAction("GrabLeft", IE_Pressed, this, &AVRMychar::GrabLeftPressed);
}

void AVRMychar::GrabRightPressed()
{
	//Collecti (Nodachi_white)
	FName RightWeaponSocket = TEXT("Sword Socket");
	TArray<AActor*> outoverlap;
	RightSword->GetOverlappingActors(outoverlap);

	//East_Sword
	FName RightEastSocket = TEXT("RightSword East");
	TArray<AActor*> outoverlap_East_Right;
	RightSword->GetOverlappingActors(outoverlap_East_Right);

	//Kitsune_Sword
	FName RightKitsuneSocket = TEXT("RightSword Kitsune");
	TArray<AActor*> outoverlap_Kitsune_Right;
	RightSword->GetOverlappingActors(outoverlap_Kitsune_Right);

	if (outoverlap.Num() > 0)
	{
		ACollecti* trycast = dynamic_cast<ACollecti*>(outoverlap[0]);
		Right_has_sword = true;

		if (trycast)
		{
			trycast->GetStaticMeshComponent()->SetSimulatePhysics(false);
			trycast->AttachToComponent(RightHand, FAttachmentTransformRules::SnapToTargetIncludingScale, RightWeaponSocket);

			if (Right_has_sword == true)
			{
				UE_LOG(LogTemp, Display, TEXT("Right Sword"));

				if (Left_has_sword == true && Right_has_sword == true)
				{
					UE_LOG(LogTemp, Display, TEXT("Both has sword"));
				}
			}
		}
	}

	if (outoverlap_Kitsune_Right.Num() > 0)
	{
		AKorean_Scabbard* trycast_Korean_Right = dynamic_cast<AKorean_Scabbard*>(outoverlap_Kitsune_Right[0]);
		Right_has_sword = true;

		if (trycast_Korean_Right)
		{
			trycast_Korean_Right->GetStaticMeshComponent()->SetSimulatePhysics(false);
			trycast_Korean_Right->AttachToComponent(RightHand, FAttachmentTransformRules::SnapToTargetIncludingScale, RightKitsuneSocket);

			if (Right_has_sword == true)
			{
				UE_LOG(LogTemp, Display, TEXT("Right Sword Kitsune"));

				if (Left_has_sword == true && Right_has_sword == true)
				{
					UE_LOG(LogTemp, Display, TEXT("Both has sword"));
				}
			}
		}
	}

	if (outoverlap_East_Right.Num() > 0)
	{
		AEast_Sword_1* trycast_East_Right = dynamic_cast<AEast_Sword_1*>(outoverlap_East_Right[0]);
		Right_has_sword = true;

		if (trycast_East_Right)
		{
			trycast_East_Right->GetStaticMeshComponent()->SetSimulatePhysics(false);
			trycast_East_Right->AttachToComponent(RightHand, FAttachmentTransformRules::SnapToTargetIncludingScale, RightEastSocket);

			if (Right_has_sword == true)
			{
				UE_LOG(LogTemp, Display, TEXT("Right Sword East"));

				if (Left_has_sword == true && Right_has_sword == true)
				{
					UE_LOG(LogTemp, Display, TEXT("Both has sword"));
				}
			}
		}
	}
}

void AVRMychar::GrabLeftPressed()
{
	//Nodachi_Black Sword
	FName LeftWeaponSocket = TEXT("LeftSword Socket");
	TArray<AActor*> outoverlap_Left;
	LeftSword->GetOverlappingActors(outoverlap_Left);

	//Kitsune_Sword
	FName LeftKitsuneSocket = TEXT("LeftSword Kitsune");
	TArray<AActor*> outoverlap_Kitsune_Left;
	LeftSword->GetOverlappingActors(outoverlap_Kitsune_Left);

	//East_Sword
	FName LeftEastSocket = TEXT("LeftSword East");
	TArray<AActor*> outoverlap_East_Left;
	LeftSword->GetOverlappingActors(outoverlap_East_Left);

	if (outoverlap_Left.Num() > 0)
	{
		ANodachi_Black* trycast_Left = dynamic_cast<ANodachi_Black*>(outoverlap_Left[0]);
		Left_has_sword = true;

		if (trycast_Left)
		{
			trycast_Left->GetStaticMeshComponent()->SetSimulatePhysics(false);
			trycast_Left->AttachToComponent(LeftHand, FAttachmentTransformRules::SnapToTargetIncludingScale, LeftWeaponSocket);

			if (Left_has_sword == true)
			{
				UE_LOG(LogTemp, Display, TEXT("Left Sword Nodachi"));

				if (Left_has_sword == true && Right_has_sword == true)
				{
					UE_LOG(LogTemp, Display, TEXT("Both has sword"));
				}
			}
		}
	}

	if (outoverlap_Kitsune_Left.Num() > 0)
	{
		AKorean_Sword1* trycast_Korean_Left = dynamic_cast<AKorean_Sword1*>(outoverlap_Kitsune_Left[0]);
		Left_has_sword = true;

		if (trycast_Korean_Left)
		{
			trycast_Korean_Left->GetStaticMeshComponent()->SetSimulatePhysics(false);
			trycast_Korean_Left->AttachToComponent(LeftHand, FAttachmentTransformRules::SnapToTargetIncludingScale, LeftKitsuneSocket);

			if (Left_has_sword == true)
			{
				UE_LOG(LogTemp, Display, TEXT("Left Sword Kitsune"));

				if (Left_has_sword == true && Right_has_sword == true)
				{
					UE_LOG(LogTemp, Display, TEXT("Both has sword"));
				}
			}
		}
	}

	if (outoverlap_East_Left.Num() > 0)
	{
		AEast_Sword_1* trycast_East_Left = dynamic_cast<AEast_Sword_1*>(outoverlap_East_Left[0]);
		Left_has_sword = true;

		if (trycast_East_Left)
		{
			trycast_East_Left->GetStaticMeshComponent()->SetSimulatePhysics(false);
			trycast_East_Left->AttachToComponent(LeftHand, FAttachmentTransformRules::SnapToTargetIncludingScale, LeftEastSocket);

			if (Left_has_sword == true)
			{
				UE_LOG(LogTemp, Display, TEXT("Left Sword East"));

				if (Left_has_sword == true && Right_has_sword == true)
				{
					UE_LOG(LogTemp, Display, TEXT("Both has sword"));
				}
			}
		}
	}
}
