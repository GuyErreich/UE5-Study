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
	TArray<FContentBrowserMenuExtender_SelectedPaths>& ContentBrowserModuleMenuExtenders = ContentBrowserModule.GetAllPathViewContextMenuExtenders();

	// FContentBrowserMenuExtender_SelectedPaths CustomCBMenuDelegate;
	// CustomCBMenuDelegate.BindRaw(this, &FFSMEditorModule::CustomCBMenuExtender);

	// ContentBrowserModuleMenuExtenders.Add(CustomCBMenuDelegate);

	ContentBrowserModuleMenuExtenders.Add(FContentBrowserMenuExtender_SelectedPaths::CreateRaw(this, &FFSMEditorModule::CustomCBMenuExtender));
}

TSharedRef<FExtender> FFSMEditorModule::CustomCBMenuExtender(const TArray<FString> &SelectedPaths)
{
	TSharedRef<FExtender> MenuExtender (new FExtender());

	if (SelectedPaths.Num() > 0)
	{
		MenuExtender->AddMenuExtension(
			"Delete", 
			EExtensionHook::After, 
			TSharedPtr<FUICommandList>(),
			FMenuExtensionDelegate::CreateRaw(this, &FFSMEditorModule::AddCBMenuEntry)
		);
	}
    return MenuExtender;
}

void FFSMEditorModule::AddCBMenuEntry(FMenuBuilder &MenuBuilder)
{
	MenuBuilder.AddMenuEntry(
		FText::FromString("Delete Unused Assets"),
		FText::FromString("Safely delete all unused assets under folder"),
		FSlateIcon(),
		FExecuteAction::CreateRaw(this, &FFSMEditorModule::OnDeleteUnusedAssetsButtonClicked)
	);
}

void FFSMEditorModule::OnDeleteUnusedAssetsButtonClicked()
{

}

#pragma endregion

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FFSMEditorModule, FSMEditor)