// Copyright Gianluca Bortolanza. All Rights Reserved.

#include "UI/UMG/NavigationDots.h"

UNavigationDots::UNavigationDots(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	NavigationDotsStyle.DotStyle = FCommonUIComponentsEditorStyle::Get().GetWidgetStyle<FCheckBoxStyle>("CommonUIComponentsEditorStyle.NavigationDotStyle");
	NavigationDotsStyle.DotStyle.UnlinkColors();
	
	NavigationDotsStyle.NavigateLeftButtonStyle = FCommonUIComponentsEditorStyle::Get().GetWidgetStyle<FButtonStyle>("CommonUIComponentsEditorStyle.NavigateLeftButtonStyle");
	NavigationDotsStyle.NavigateLeftButtonStyle.UnlinkColors();
	
	NavigationDotsStyle.NavigateRightButtonStyle = FCommonUIComponentsEditorStyle::Get().GetWidgetStyle<FButtonStyle>("CommonUIComponentsEditorStyle.NavigateRightButtonStyle");
	NavigationDotsStyle.NavigateRightButtonStyle.UnlinkColors();
}

TSharedRef<SWidget> UNavigationDots::RebuildWidget()
{
	NavigationDots = SNew(SNavigationDots)
		.OnDotSelected(BIND_UOBJECT_DELEGATE(FDotSelectedDelegate, SlateDotSelected))
		.NumberOfDots(NumberOfDots)
		.DotsPadding(DotsPadding)
		.ShowNavigationButtons(NavigationDotsStyle.bShowNavigationButtons)
		.DotStyle(&NavigationDotsStyle.DotStyle)
		.NavigateLeftButtonStyle(&NavigationDotsStyle.NavigateLeftButtonStyle)
		.NavigateRightButtonStyle(&NavigationDotsStyle.NavigateRightButtonStyle);
	
	return NavigationDots.ToSharedRef();
}

void UNavigationDots::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	
	NavigationDots.Reset();
}

void UNavigationDots::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	
	if (!NavigationDots.IsValid())
	{
		return;
	}

	NavigationDots->SetNumberOfDots(NumberOfDots);
	NavigationDots->SetDotsPadding(DotsPadding);
	NavigationDots->ShowNavigationButtons(NavigationDotsStyle.bShowNavigationButtons);
	
	NavigationDots->SetDotStyle(NavigationDotsStyle.DotStyle);
	NavigationDots->SetNavigateLeftButtonStyle(NavigationDotsStyle.NavigateLeftButtonStyle);
	NavigationDots->SetNavigateRightButtonStyle(NavigationDotsStyle.NavigateRightButtonStyle);
}

#if WITH_EDITOR
#define LOCTEXT_NAMESPACE "NavigationDots"

const FText UNavigationDots::GetPaletteCategory()
{
	return LOCTEXT("Common", "Common");
}

#undef LOCTEXT_NAMESPACE
#endif

void UNavigationDots::SetSelectedDot(const int32 InDotIndex)
{
	if (NavigationDots.IsValid())
	{
		NavigationDots->SetDotChoice(InDotIndex);
		InvalidateLayoutAndVolatility();
	}
}

int32 UNavigationDots::GetSelectedDot() const
{
	if (NavigationDots.IsValid())
	{
		return NavigationDots->GetDotChoice();
	}
	
	return INDEX_NONE;
}

void UNavigationDots::SetNumberOfDots(const int32 InNumberOfDots)
{
	NumberOfDots = InNumberOfDots;
	
	if (NavigationDots.IsValid())
	{
		NavigationDots->SetNumberOfDots(NumberOfDots);
	}
}

int32 UNavigationDots::GetNumberOfDots() const
{
	return NumberOfDots;
}

void UNavigationDots::SetDotsPadding(const FMargin& InPadding)
{
	DotsPadding = InPadding;
	
	if (NavigationDots.IsValid())
	{
		NavigationDots->SetDotsPadding(InPadding);
	}
}

void UNavigationDots::ShowNavigationButtons(const bool bInShow)
{
	NavigationDotsStyle.bShowNavigationButtons = bInShow;
	
	if (NavigationDots.IsValid())
	{
		NavigationDots->SetDotsPadding(bInShow);
	}
}

bool UNavigationDots::IsShowingNavigationButtons() const
{
	return NavigationDotsStyle.bShowNavigationButtons;
}

void UNavigationDots::SlateDotSelected(const int32 InDotIndex) const
{
	if (OnDotSelected.IsBound())
	{
		OnDotSelected.Broadcast(InDotIndex);
	}
}
