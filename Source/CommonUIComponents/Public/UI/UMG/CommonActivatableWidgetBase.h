// Copyright Gianluca Bortolanza. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"

#include "CommonActivatableWidgetBase.generated.h"

UCLASS()
class COMMONUICOMPONENTS_API UCommonActivatableWidgetBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:

	// Begin UCommonActivatableWidget override
	virtual void NativeOnActivated() override;
	virtual void NativeOnDeactivated() override;
	// End UCommonActivatableWidget override

	DECLARE_MULTICAST_DELEGATE_OneParam(FOnActivatableWidgetUpdatedSignature, UCommonActivatableWidgetBase*);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActivatableWidgetUpdatedSignatureBP, UCommonActivatableWidgetBase*, Widget);

	FOnActivatableWidgetUpdatedSignature OnPlayIn;
	FOnActivatableWidgetUpdatedSignature OnPlayOut;

	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "OnPlayIn"))
	FOnActivatableWidgetUpdatedSignatureBP OnPlayInBP;

	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "OnPlayOut"))
	FOnActivatableWidgetUpdatedSignatureBP OnPlayOutBP;

protected:

	UFUNCTION(BlueprintNativeEvent)
	void PlayIn();
	virtual void PlayIn_Implementation();

	UFUNCTION(BlueprintNativeEvent)
	void PlayOut();
	virtual void PlayOut_Implementation();

	UFUNCTION(BlueprintCallable)
	void NotifyPlayInComplete();

	UFUNCTION(BlueprintCallable)
	void NotifyPlayOutComplete();
};
