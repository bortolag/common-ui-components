// Copyright Gianluca Bortolanza. All Rights Reserved.

#include "UI/UMG/CommonActivatableWidgetBase.h"

void UCommonActivatableWidgetBase::NativeOnActivated()
{
	Super::NativeOnActivated();

	PlayIn();
}

void UCommonActivatableWidgetBase::NativeOnDeactivated()
{
	Super::NativeOnDeactivated();

	PlayOut();
}

void UCommonActivatableWidgetBase::PlayIn_Implementation()
{
	NotifyPlayInComplete();
}

void UCommonActivatableWidgetBase::PlayOut_Implementation()
{
	NotifyPlayOutComplete();
}

void UCommonActivatableWidgetBase::NotifyPlayInComplete()
{
	OnPlayIn.Broadcast(this);
	OnPlayInBP.Broadcast(this);
}

void UCommonActivatableWidgetBase::NotifyPlayOutComplete()
{
	OnPlayOut.Broadcast(this);
	OnPlayOutBP.Broadcast(this);
}
