/**
@author		Shun Moriya
@copyright	2024- Shun Moriya
All Rights Reserved.

https://www.youtube.com/channel/UCkLXe57GpUyaOoj2ycREU1Q
*/

#pragma once

#include <CoreMinimal.h>
#include <Modules/ModuleManager.h>

class FDrawLotsModule : public IModuleInterface
{
public:
	// IModuleInterface implementation
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
