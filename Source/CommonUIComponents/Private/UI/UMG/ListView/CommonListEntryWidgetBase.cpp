// Copyright Gianluca Bortolanza. All Rights Reserved.

#include "UI/UMG/ListView/CommonListEntryWidgetBase.h"

#include "MVVMViewModelBase.h"
#include "Utility/CommonUIFunctionLibrary.h"

void UCommonListEntryWidgetBase::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	if (UMVVMViewModelBase* ViewModel = Cast<UMVVMViewModelBase>(ListItemObject))
	{
		UCommonUIFunctionLibrary::SetViewModel(this, ViewModel);
	}
}
