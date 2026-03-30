// Copyright Gianluca Bortolanza. All Rights Reserved.

#include "Utility/CommonUIFunctionLibrary.h"

#include "MVVMViewModelBase.h"

void UCommonUIFunctionLibrary::SetViewModel(const UUserWidget* InWidget, UMVVMViewModelBase* InViewModel)
{
	if (!IsValid(InWidget))
	{
		return;
	}

	UMVVMView* View = Cast<UMVVMView>(InWidget->GetExtension(UMVVMView::StaticClass()));
	if (!IsValid(View))
	{
		return;
	}

	View->SetViewModelByClass(InViewModel);
}
