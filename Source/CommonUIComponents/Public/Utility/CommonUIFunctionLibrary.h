// Copyright Gianluca Bortolanza. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "View/MVVMView.h"

#include "CommonUIFunctionLibrary.generated.h"

UCLASS()
class COMMONUICOMPONENTS_API UCommonUIFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	template <typename ViewModelT = UMVVMViewModelBase>
	static ViewModelT* GetViewModel(const UUserWidget* InWidget, const FName& InViewModelName)
	{
		UMVVMView* View = Cast<UMVVMView>(InWidget->GetExtension(UMVVMView::StaticClass()));
		if (!IsValid(View))
		{
			return nullptr;
		}

		return View->GetViewModel(InViewModelName);
	}

	UFUNCTION(BlueprintCallable)
	static void SetViewModel(const UUserWidget* InWidget, UMVVMViewModelBase* InViewModel);
};
