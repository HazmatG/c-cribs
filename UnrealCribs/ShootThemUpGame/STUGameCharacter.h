// ShootThemUp Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "STUGameCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASTUGameCharacter(const FObjectInitializer& ObjInit);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent *CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArmComp;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
      bool IsSprinting() const;

    private:
      bool IsMovingForward;
      bool WantsToRun = false;

      void MoveForward(float Amount);
      void MoveRight(float Amount);
      void LookUp(float Amount);
      void TurnAround(float Amount);
	  void SprintStart();
	  void SprintStop();
};
