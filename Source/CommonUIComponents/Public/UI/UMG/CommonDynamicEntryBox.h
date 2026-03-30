// Copyright Gianluca Bortolanza. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/DynamicEntryBox.h"

#include "CommonDynamicEntryBox.generated.h"

class UMVVMViewModelBase;

UCLASS(BlueprintType)
class COMMONUICOMPONENTS_API UCommonDynamicEntryBox : public UDynamicEntryBox
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void SetListEntries(const TArray<UMVVMViewModelBase*>& InListEntries);
};
