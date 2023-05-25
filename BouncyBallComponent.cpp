#include "BouncyBallComponent.h"
#include "Components/PrimitiveComponent.h"

// Sets default values for this component's properties
UBouncyBallComponent::UBouncyBallComponent()
{
    Restitution = 1.0f;
    Friction = 0.0f;
}

// Called when the game starts
void UBouncyBallComponent::BeginPlay()
{
    Super::BeginPlay();

    MakeBouncy();
}

void UBouncyBallComponent::MakeBouncy()
{
    // Get the first primitive component we can find on this actor
    UPrimitiveComponent* PrimComp = GetOwner()->FindComponentByClass<UPrimitiveComponent>();

    // If the actor has a primitive component, change its physical material properties
    if (PrimComp)
    {
        // Create a new physical material instance
        UPhysicalMaterial* PhysMat = PrimComp->GetBodySetup()->GetPhysMaterial();

        if (PhysMat)
        {
            // Change the properties of the physical material
            PhysMat->Friction = Friction;
            PhysMat->Restitution = Restitution;
            PhysMat->UpdatePhysXMaterial();
        }
    }
}
