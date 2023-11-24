// Copyright Epic Games, Inc. All Rights Reserved.

#include "FSMEditor.h"
#include "ContentBrowserModule.h"

#define LOCTEXT_NAMESPACE "FFSMEditorModule"

void FFSMEditorModule::StartupModule()
{
	InitCBMenuExtention();
}

void FFSMEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#pragma region ContentBrowserMenuExtension

void FFSMEditorModule::InitCBMenuExtention()
{
	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
}

#pragma endregion

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FFSMEditorModule, FSMEditor)