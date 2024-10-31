// Copyright Gianluca Bortolanza. All Rights Reserved.

#pragma once

#include <Components/ContentWidget.h>

#include "UI/Slate/CommonUIComponentsStyles.h"
#include "UI/Slate/SNavigationDots.h"

#include "NavigationDots.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNavigationDotsEvent, const int32, InDotIndex);

// Widget that contains a SNavigationDots
UCLASS(MinimalAPI)
class UNavigationDots : public UContentWidget
{
	
	GENERATED_BODY()
	
public:
	
	UNavigationDots(const FObjectInitializer& ObjectInitializer);
	
	// Begin UWidget override
	virtual TSharedRef<SWidget> RebuildWidget() override;
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	virtual void SynchronizeProperties() override;
	virtual const FText GetPaletteCategory() override;
	// End UWidget override
	
	// Sets a new selected dot after the given index
	UFUNCTION(BlueprintCallable, Category = "Navigation Dots")
	COMMONUICOMPONENTS_API void SetSelectedDot(const int32 InDotIndex);
	
	// Returns the index of the currently selected dot
	UFUNCTION(BlueprintPure, Category = "Navigation Dots")
	COMMONUICOMPONENTS_API int32 GetSelectedDot() const;
	
	// Sets the new total number of dots to display
	UFUNCTION(BlueprintCallable, Category = "Navigation Dots")
	COMMONUICOMPONENTS_API void SetNumberOfDots(const int32 InNumberOfDots);
	
	// Returns the number of dots contained in the widget
	UFUNCTION(BlueprintPure, Category = "Navigation Dots")
	COMMONUICOMPONENTS_API int32 GetNumberOfDots() const;
	
	// Sets the new padding between each dot
	UFUNCTION(BlueprintCallable, Category = "Navigation Dots")
	COMMONUICOMPONENTS_API void SetDotsPadding(const FMargin& InPadding);
	
	// Sets if we should show the navigation buttons or not
	UFUNCTION(BlueprintCallable, Category = "Navigation Dots")
	COMMONUICOMPONENTS_API void ShowNavigationButtons(const bool bInShow);

	// Returns true if we are currently showing the navigation buttons on the widget
	UFUNCTION(BlueprintPure, Category = "Navigation Dots")
	COMMONUICOMPONENTS_API bool IsShowingNavigationButtons() const;
	
	// The total number of dots to display
	UPROPERTY(EditAnywhere, Category="Navigation Dots")
	int32 NumberOfDots = 3;
	
	// The padding between each dot
	UPROPERTY(EditAnywhere, Category="Navigation Dots")
	FMargin DotsPadding = FMargin(8.0f);
	
	UPROPERTY(EditAnywhere, Category=Appearance)
	FNavigationDotsStyle NavigationDotsStyle = FNavigationDotsStyle();
	
	// Called when a new navigation dot has been selected
	UPROPERTY(BlueprintAssignable, Category="Navigation Dots|Event")
	FOnNavigationDotsEvent OnDotSelected;
	
protected:
	
	// Bound to the slate widget delegate event fired whenever a new dot has been selected
	void SlateDotSelected(const int32 InDotIndex) const;
	
private:
	
	// Cached pointer to the underlying slate navigation dots owned by this UWidget 
	TSharedPtr<SNavigationDots> NavigationDots;
	
};