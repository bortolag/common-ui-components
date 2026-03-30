// Copyright Gianluca Bortolanza. All Rights Reserved.

#include "UI/UMG//CommonDynamicEntryBox.h"

#include "Utility/CommonUIFunctionLibrary.h"

void UCommonDynamicEntryBox::SetListEntries(const TArray<UMVVMViewModelBase*>& InListEntries)
{
	Reset();

	for (UMVVMViewModelBase* InListEntry : InListEntries)
	{
		UUserWidget* NewWidget = CreateEntry<UUserWidget>();
		if (IsValid(NewWidget))
		{
			UCommonUIFunctionLibrary::SetViewModel(NewWidget, InListEntry);
		}
	}
}
