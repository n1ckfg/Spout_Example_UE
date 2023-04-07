// Copyright Off World Live Limited, 2020-2022. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogOWLToolkit, Log, All);

class LIVESTREAMINGTOOLKIT_API FLivestreamingToolkitModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;


public:
	static bool IgnoreUnrealHardwareEncoding();
	static bool SuggestLoadingHardwareEncodersPlugin();
	static void SetHardwareEncodersPendingRestart();
	static bool IsHardwareEncodersPluginPendingRestart();
private:
	static bool bHardwareEncodingModuleLoaded;
	static bool bIsNvidia;
	static bool bForceFfmpegOnlyPipeline;
	static bool bHardwareEncodersPendingRestart;
	void LoadMediaOutput();

	void LoadNDI();
	void LoadWebcam();

	FDelegateHandle OnFEngineLoopInitCompleteHandle;
	FDelegateHandle OnWorldAddedHandle;
	FDelegateHandle OnWorldDestroyedHandle;
	void OnFEngineLoopInitComplete();
};
