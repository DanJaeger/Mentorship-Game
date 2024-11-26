// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AdvancedCharacter.generated.h"

UCLASS()
class MENTORIA_API AAdvancedCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Constructor
	AAdvancedCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Math|Interpolation", meta = (ScriptMethod = "InterpTo", Keywords = "position"))
	void SetCameraToOriginalPosition(FVector originalPosition, float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "Math|Interpolation", meta = (ScriptMethod = "InterpTo", Keywords = "position"))
	void SetCameraToOriginalRotation(FRotator originalRotation, float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "Math|Interpolation", meta = (ScriptMethod = "InterpTo", Keywords = "position"))
	void UpdateCameraPosition(FVector targetPosition, float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "Math|Interpolation", meta = (ScriptMethod = "InterpTo", Keywords = "position"))
	void UpdateCameraRotation(FRotator targetRotation, float DeltaTime);

};
