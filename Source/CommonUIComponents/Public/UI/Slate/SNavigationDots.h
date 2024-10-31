// Copyright Gianluca Bortolanza. All Rights Reserved.

#pragma once

#include <Widgets/SCompoundWidget.h>

#include "CommonUIComponentsStyles.h"

DECLARE_DELEGATE_OneParam(FDotSelectedDelegate, const int32);

// Navigation Dots slate widget
class COMMONUICOMPONENTS_API SNavigationDots : public SCompoundWidget
{
	
public:
	
	SLATE_BEGIN_ARGS(SNavigationDots)
		: _NumberOfDots(0),
		_DotsPadding(8.0f),
		_ShowNavigationButtons(true),
		_DotStyle(&FCommonUIComponentsEditorStyle::Get().GetWidgetStyle<FCheckBoxStyle>("CommonUIComponentsEditorStyle.NavigationDotStyle")),
		_NavigateLeftButtonStyle(&FCommonUIComponentsEditorStyle::Get().GetWidgetStyle<FButtonStyle>("CommonUIComponentsEditorStyle.NavigateLeftButtonStyle")),
		_NavigateRightButtonStyle(&FCommonUIComponentsEditorStyle::Get().GetWidgetStyle<FButtonStyle>("CommonUIComponentsEditorStyle.NavigateRightButtonStyle"))
	{}
	
	// The number of total dots to display
	SLATE_ATTRIBUTE(int32, NumberOfDots)

	// The amount of padding between each dot
	SLATE_ATTRIBUTE(FMargin, DotsPadding)

	// The control variable that dictate if the navigation buttons should be setup or not
	SLATE_ATTRIBUTE(bool, ShowNavigationButtons)

	// The style of the dots
	SLATE_STYLE_ARGUMENT(FCheckBoxStyle, DotStyle);

	// The style of the navigate-left button
	SLATE_STYLE_ARGUMENT(FButtonStyle, NavigateLeftButtonStyle);

	// The style of the navigate-right button
	SLATE_STYLE_ARGUMENT(FButtonStyle, NavigateRightButtonStyle);

	// Called when a new dot has been selected
	SLATE_EVENT(FDotSelectedDelegate, OnDotSelected)

	SLATE_END_ARGS()

	// Constructs this widget with InArgs
	void Construct(const FArguments& InArgs);

	// Sets the given dot's index as the new selected one
	void SetDotChoice(const int32 InDotIndex);

	// Sets a new number of dots in the widget
	void SetNumberOfDots(const int32 InNumberOfDots);

	// Returns the total number of dots in the widget
	int32 GetNumberOfDots() const;
	
	// Returns the index of the selected dot
	int32 GetDotChoice() const;

	// Sets a new padding for the slots of this widget
	void SetDotsPadding(const FMargin& InDotsPadding);
	
	// Sets if the navigation button should be shown or not
	void ShowNavigationButtons(const bool bInShowButtons);

	// Sets the style applied to each dot
	void SetDotStyle(const FCheckBoxStyle& InDotStyle);

	// Sets the style applied to the navigate-left button
	void SetNavigateLeftButtonStyle(const FButtonStyle& InButtonStyle);

	// Sets the style applied to the navigate-right button
	void SetNavigateRightButtonStyle(const FButtonStyle& InButtonStyle);

protected:

	// Builds the navigations dots
	void BuildNavigationDots();

	// Updates the padding of the slots in the widget
	void UpdateDotsPadding() const;

	// Returns true if moving left can be done
	bool CanNavigateLeft() const;
	
	// Handles left navigation
	FReply HandleLeft();

	// Returns true if moving right can be done
	bool CanNavigateRight() const;

	// Handles right navigation
	FReply HandleRight();

	// Executes the OnDotSelected delegate if bound
	void ExecuteOnDotSelected() const;

private:

	// The container of the dots and navigation buttons
	TSharedPtr<SHorizontalBox> DotsContainer;

	// The last selected radio button index
	int32 DotChoice = 0;

	// The total number of dots displayed
	int32 NumberOfDots = 0;

	// The padding applied for each slot
	FMargin DotsPadding = FMargin(0.0f);

	// The control variable that dictates if the navigation buttons should be added or not
	bool bShowNavigationButtons = true;

	// The style applied to each dot
	FCheckBoxStyle DotStyle = FCheckBoxStyle();

	// The style applied to the navigate-left button
	FButtonStyle NavigateLeftButtonStyle = FButtonStyle();

	// The style applied to the navigate-right button
	FButtonStyle NavigateRightButtonStyle = FButtonStyle();

	// The delegate to execute when a new dot has been selected
	FDotSelectedDelegate OnDotSelected;
	
};