// Copyright Gianluca Bortolanza. All Rights Reserved.

#include "UI/Slate/CommonUIComponentsStyles.h"

#include <Interfaces/IPluginManager.h>
#include <Styling/SlateStyleMacros.h>
#include <Styling/SlateStyleRegistry.h>

FNavigationDotsStyle::FNavigationDotsStyle()
	: DotStyle(FCommonUIComponentsEditorStyle::Get().GetWidgetStyle<FCheckBoxStyle>("CommonUIComponentsEditorStyle.NavigationDotStyle"))
	, NavigateLeftButtonStyle(FCommonUIComponentsEditorStyle::Get().GetWidgetStyle<FButtonStyle>("CommonUIComponentsEditorStyle.NavigateLeftButtonStyle")) 
	, NavigateRightButtonStyle(FCommonUIComponentsEditorStyle::Get().GetWidgetStyle<FButtonStyle>("CommonUIComponentsEditorStyle.NavigateRightButtonStyle"))
{
}

FNavigationDotsStyle::FNavigationDotsStyle(const FNavigationDotsStyle&) = default;

FNavigationDotsStyle::~FNavigationDotsStyle() = default;

void FNavigationDotsStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	DotStyle.GetResources(OutBrushes);
	NavigateLeftButtonStyle.GetResources(OutBrushes);
	NavigateRightButtonStyle.GetResources(OutBrushes);
}

const FName FNavigationDotsStyle::TypeName( TEXT("FNavigationDotsStyle") );

const FNavigationDotsStyle& FNavigationDotsStyle::GetDefault()
{
	static FNavigationDotsStyle Default;
	return Default;
}

void FNavigationDotsStyle::SetDotStyle(const FCheckBoxStyle& InButtonStyle)
{
	DotStyle = InButtonStyle;
}

void FNavigationDotsStyle::SetNavigateLeftButtonStyle(const FButtonStyle& InButtonStyle)
{
	NavigateLeftButtonStyle = InButtonStyle;
}

void FNavigationDotsStyle::SetNavigateRightButtonStyle(const FButtonStyle& InButtonStyle)
{
	NavigateRightButtonStyle = InButtonStyle;
}

FCommonUIComponentsEditorStyle::FCommonUIComponentsEditorStyle() : FSlateStyleSet("CommonUIComponentsEditorStyle")
{
	const FVector2D Icon16x16 = FVector2D(16.0f, 16.0f);

	const FString& PluginDirectory = IPluginManager::Get().FindPlugin(TEXT("CommonUIComponents"))->GetBaseDir();
	SetContentRoot(PluginDirectory / TEXT("/Content/Slate"));
	
	const FCheckBoxStyle DotCheckBoxStyle = FCheckBoxStyle()
		.SetCheckBoxType(ESlateCheckBoxType::CheckBox)
		
		.SetUncheckedImage(IMAGE_BRUSH_SVG("/Common/radio-off", Icon16x16, FStyleColors::Dropdown))
		.SetUncheckedHoveredImage(IMAGE_BRUSH_SVG("/Common/radio-off", Icon16x16, FStyleColors::Hover))
		.SetUncheckedPressedImage(IMAGE_BRUSH_SVG("/Common/radio-off", Icon16x16, FStyleColors::Dropdown))
		.SetCheckedImage(IMAGE_BRUSH_SVG("/Common/radio-on", Icon16x16, FStyleColors::Primary))
		.SetCheckedHoveredImage(IMAGE_BRUSH_SVG("/Common/radio-on", Icon16x16, FStyleColors::PrimaryHover))
		.SetCheckedPressedImage(IMAGE_BRUSH_SVG("/Common/radio-on", Icon16x16, FStyleColors::Primary))
		.SetUndeterminedImage(IMAGE_BRUSH_SVG("/Common/radio-off", Icon16x16, FStyleColors::White25))
		.SetUndeterminedHoveredImage(IMAGE_BRUSH_SVG("/Common/radio-off", Icon16x16, FStyleColors::ForegroundHover))
		.SetUndeterminedPressedImage(IMAGE_BRUSH_SVG("/Common/radio-off", Icon16x16, FStyleColors::ForegroundHover))
		
		.SetForegroundColor(FLinearColor::White)
		.SetHoveredForegroundColor(FLinearColor::White)
		.SetPressedForegroundColor(FLinearColor::White)
		.SetCheckedForegroundColor(FLinearColor::White)
		.SetCheckedHoveredForegroundColor(FLinearColor::White)
		.SetCheckedPressedForegroundColor(FLinearColor::White)
		.SetUndeterminedForegroundColor(FLinearColor::White)
		
		.SetPadding(FMargin(4.0f));
	
	Set("CommonUIComponentsEditorStyle.NavigationDotStyle", DotCheckBoxStyle);

	const FButtonStyle& NavigateLeftButtonStyle = FButtonStyle()
		.SetNormal(IMAGE_BRUSH_SVG("/Common/chevron-left", Icon16x16, FStyleColors::Dropdown))
		.SetHovered(IMAGE_BRUSH_SVG("/Common/chevron-left", Icon16x16, FStyleColors::Hover))
		.SetPressed(IMAGE_BRUSH_SVG("/Common/chevron-left", Icon16x16, FStyleColors::Primary))
		.SetDisabled(IMAGE_BRUSH_SVG("/Common/chevron-left", Icon16x16, FStyleColors::Dropdown))
		
		.SetNormalForeground(FLinearColor::White)
		.SetHoveredForeground(FLinearColor::White)
		.SetPressedForeground(FLinearColor::White)
		.SetDisabledForeground(FLinearColor::White)
		
		.SetNormalPadding(FMargin(0.0f))
		.SetPressedPadding(FMargin(0.0f));

	Set("CommonUIComponentsEditorStyle.NavigateLeftButtonStyle", NavigateLeftButtonStyle);
	
	const FButtonStyle& NavigateRightButtonStyle = FButtonStyle()
		.SetNormal(IMAGE_BRUSH_SVG("/Common/chevron-right", Icon16x16, FStyleColors::Dropdown))
		.SetHovered(IMAGE_BRUSH_SVG("/Common/chevron-right", Icon16x16, FStyleColors::Hover))
		.SetPressed(IMAGE_BRUSH_SVG("/Common/chevron-right", Icon16x16, FStyleColors::Primary))
		.SetDisabled(IMAGE_BRUSH_SVG("/Common/chevron-right", Icon16x16, FStyleColors::Dropdown))
		
		.SetNormalForeground(FLinearColor::White)
		.SetHoveredForeground(FLinearColor::White)
		.SetPressedForeground(FLinearColor::White)
		.SetDisabledForeground(FLinearColor::White)
		
		.SetNormalPadding(FMargin(0.0f))
		.SetPressedPadding(FMargin(0.0f));
	
	Set("CommonUIComponentsEditorStyle.NavigateRightButtonStyle", NavigateRightButtonStyle);
	
	FSlateStyleRegistry::RegisterSlateStyle(*this);
}

FCommonUIComponentsEditorStyle::~FCommonUIComponentsEditorStyle()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*this);
}

FCommonUIComponentsEditorStyle& FCommonUIComponentsEditorStyle::Get()
{
	static FCommonUIComponentsEditorStyle FCommonUIComponentsEditorStyle;
	return FCommonUIComponentsEditorStyle;
}