// Copyright Gianluca Bortolanza. All Rights Reserved.

#include "ViewModel/CommonViewModelBase.h"

void UCommonViewModelBase::PostInitProperties()
{
	Super::PostInitProperties();

	if (!HasAnyFlags(RF_ClassDefaultObject))
	{
		Initialize();
	}
}

void UCommonViewModelBase::BeginDestroy()
{
	if (!HasAnyFlags(RF_ClassDefaultObject))
	{
		Deinitialize();
	}

	Super::BeginDestroy();
}
