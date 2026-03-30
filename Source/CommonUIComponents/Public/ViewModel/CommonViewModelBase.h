// Copyright Gianluca Bortolanza. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"

#include "CommonViewModelBase.generated.h"

UCLASS()
class COMMONUICOMPONENTS_API UCommonViewModelBase : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	
	// Begin UObject override
	virtual void PostInitProperties() override;
	virtual void BeginDestroy() override;
	// End UObject override

protected:

	virtual void Initialize() {}
	virtual void Deinitialize() {}
	
};
