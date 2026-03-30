// Copyright Gianluca Bortolanza. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "Blueprint/IUserObjectListEntry.h"

#include "CommonListEntryWidgetBase.generated.h"

UCLASS()
class COMMONUICOMPONENTS_API UCommonListEntryWidgetBase : public UCommonButtonBase, public IUserObjectListEntry
{
	GENERATED_BODY()

public:

	// Begin IUserObjectListEntry interface
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	// End IUserObjectListEntry interface

};
