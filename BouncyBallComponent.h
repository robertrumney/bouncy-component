#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BouncyBallComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BOUNCE_API UBouncyBallComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UBouncyBallComponent();

    // Called when the game starts
    virtual void BeginPlay() override;

protected:
    UPROPERTY(EditAnywhere, Category = "Physics")
    float Restitution;

    UPROPERTY(EditAnywhere, Category = "Physics")
    float Friction;

private:
    void MakeBouncy();
};
