// Fill out your copyright notice in the Description page of Project Settings.


#include "AdvancedCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetMathLibrary.h"
// Sets default values
AAdvancedCharacter::AAdvancedCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAdvancedCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAdvancedCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAdvancedCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAdvancedCharacter::SetCameraToOriginalPosition(FVector originalPosition, float DeltaTime)
{
	UCameraComponent* CameraComponent = this->FindComponentByClass<UCameraComponent>();
	if (CameraComponent)
	{
		FVector CameraLocation = CameraComponent->GetRelativeLocation();
		FVector newLocation = UKismetMathLibrary::VInterpTo(CameraLocation, originalPosition, DeltaTime, 5.0f);
		CameraComponent->SetRelativeLocation(newLocation, true);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Camera Component not found!"));
	}
}

void AAdvancedCharacter::SetCameraToOriginalRotation(FRotator originalRotation, float DeltaTime)
{
	UCameraComponent* CameraComponent = this->FindComponentByClass<UCameraComponent>();
	if (CameraComponent)
	{
		FRotator CameraRotation = CameraComponent->GetRelativeRotation();
		FRotator newRotation = UKismetMathLibrary::RInterpTo(CameraRotation, originalRotation, DeltaTime, 5.0f);
		newRotation.Roll = 0.0f;
		CameraComponent->SetRelativeRotation(newRotation, false);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Camera Component not found!"));
	}
}

void AAdvancedCharacter::UpdateCameraPosition(FVector targetPosition, float DeltaTime)
{
	UCameraComponent* CameraComponent = this->FindComponentByClass<UCameraComponent>();
	if (CameraComponent)
	{
		FVector CameraLocation = CameraComponent->GetComponentLocation();
		FVector newLocation = UKismetMathLibrary::VInterpTo(CameraLocation, targetPosition, DeltaTime, 1.5f);
		CameraComponent->SetWorldLocation(newLocation, true);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Camera Component not found!"));
	}
}

void AAdvancedCharacter::UpdateCameraRotation(FRotator targetRotation, float DeltaTime)
{
	UCameraComponent* CameraComponent = this->FindComponentByClass<UCameraComponent>();
	if (CameraComponent)
	{
		FRotator CameraRotation = CameraComponent->GetComponentRotation();
		FRotator newRotation = UKismetMathLibrary::RInterpTo(CameraRotation, targetRotation, DeltaTime, 1.5f);
		newRotation.Roll = 0.0f;
		CameraComponent->SetWorldRotation(newRotation, false);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Camera Component not found!"));
	}
}



