// Copyright Gianluca Bortolanza. All Rights Reserved.

#pragma once

#include <Styling/SlateWidgetStyle.h>

#include "CommonUIComponentsStyles.generated.h"


// Represents the appearance of a SNavigationDots
USTRUCT(BlueprintType)
struct FNavigationDotsStyle : public FSlateWidgetStyle
{
	
	GENERATED_BODY()
	
public:
	
	COMMONUICOMPONENTS_API FNavigationDotsStyle();
	
	COMMONUICOMPONENTS_API FNavigationDotsStyle(const FNavigationDotsStyle&);
	
	COMMONUICOMPONENTS_API virtual ~FNavigationDotsStyle();
	
	COMMONUICOMPONENTS_API virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	
	static COMMONUICOMPONENTS_API const FName TypeName;
	
	virtual const FName GetTypeName() const override { return TypeName; };
	
	static COMMONUICOMPONENTS_API const FNavigationDotsStyle& GetDefault();
	
	void SetDotStyle(const FCheckBoxStyle& InButtonStyle);
	
	void SetNavigateLeftButtonStyle(const FButtonStyle& InButtonStyle);
	
	void SetNavigateRightButtonStyle(const FButtonStyle& InButtonStyle);
	
	// The navigation dot appearance
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Appearance)
	FCheckBoxStyle DotStyle;

	// Controls if the widget should display the navigation buttons or not
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Appearance)
	bool bShowNavigationButtons = true;
	
	// The navigation left button appearance
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Appearance, meta = (EditCondition="bShowNavigationButtons"))
	FButtonStyle NavigateLeftButtonStyle;
	
	// The navigation right button appearance
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Appearance, meta = (EditCondition="bShowNavigationButtons"))
	FButtonStyle NavigateRightButtonStyle;
	
};

// Set of slate styles for the navigation dots widgets
class FCommonUIComponentsEditorStyle : public FSlateStyleSet
{
	
public:
	
	FCommonUIComponentsEditorStyle();
	
	~FCommonUIComponentsEditorStyle();
	
	static FCommonUIComponentsEditorStyle& Get();

};
