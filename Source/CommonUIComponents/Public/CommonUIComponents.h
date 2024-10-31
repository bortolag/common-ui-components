// Copyright Gianluca Bortolanza. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FCommonUIComponentsModule : public IModuleInterface
{
	
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
};
