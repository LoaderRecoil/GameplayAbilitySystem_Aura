// Copyright LoaderRecoil

#pragma once

#include "CoreMinimal.h"
#include "UI/WigetController/AuraWidgetController.h"
#include "AttributeWidgetController.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAttributeWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()
	
public:

	virtual void BindCallbacksToDependencies() override;
	virtual void BroadcastInitialValues() override;
};
