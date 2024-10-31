// Copyright Gianluca Bortolanza. All Rights Reserved.

#include "UI/Slate/SNavigationDots.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SNavigationDots::Construct(const FArguments& InArgs)
{
	NumberOfDots = InArgs._NumberOfDots.Get();
	DotsPadding = InArgs._DotsPadding.Get();
	bShowNavigationButtons = InArgs._ShowNavigationButtons.Get();
	DotStyle = *InArgs._DotStyle;
	NavigateLeftButtonStyle = *InArgs._NavigateLeftButtonStyle;
	NavigateRightButtonStyle = *InArgs._NavigateRightButtonStyle;
	OnDotSelected = InArgs._OnDotSelected;

	DotsContainer = SNew(SHorizontalBox);
	this->ChildSlot
	[
		DotsContainer.ToSharedRef()
	];

	BuildNavigationDots();
}

void SNavigationDots::SetDotChoice(const int32 InDotIndex)
{
	DotChoice = FMath::Clamp(InDotIndex, 0, NumberOfDots - 1);
	
	ExecuteOnDotSelected();
}

void SNavigationDots::SetNumberOfDots(const int32 InNumberOfDots)
{
	NumberOfDots = FMath::Max(0, InNumberOfDots);
	
	BuildNavigationDots();
}

int32 SNavigationDots::GetNumberOfDots() const
{
	return NumberOfDots;
}

int32 SNavigationDots::GetDotChoice() const
{
	return NumberOfDots > 0 ? DotChoice : INDEX_NONE;
}

void SNavigationDots::SetDotsPadding(const FMargin& InDotsPadding)
{
	DotsPadding = InDotsPadding;
	
	UpdateDotsPadding();
}

void SNavigationDots::ShowNavigationButtons(const bool bInShowButtons)
{
	bShowNavigationButtons = bInShowButtons;

	BuildNavigationDots();
}

void SNavigationDots::SetDotStyle(const FCheckBoxStyle& InDotStyle)
{
	DotStyle = InDotStyle;
}

void SNavigationDots::SetNavigateLeftButtonStyle(const FButtonStyle& InButtonStyle)
{
	NavigateLeftButtonStyle = InButtonStyle;
}

void SNavigationDots::SetNavigateRightButtonStyle(const FButtonStyle& InButtonStyle)
{
	NavigateRightButtonStyle = InButtonStyle;
}

void SNavigationDots::BuildNavigationDots()
{
	if (!DotsContainer.IsValid())
	{
		return;
	}
	
	DotsContainer->ClearChildren();

	if(bShowNavigationButtons)
	{
		DotsContainer->AddSlot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		.Padding(DotsPadding)
		[
			SNew(SButton)
			.ButtonStyle(&NavigateLeftButtonStyle)
			.ContentPadding(FMargin(0.0f))
			.OnClicked(this, &SNavigationDots::HandleLeft)
			.IsEnabled(this, &SNavigationDots::CanNavigateLeft)
		];
	}
	
	for (int32 DotIndex = 0; DotIndex < NumberOfDots; DotIndex++)
	{
		DotsContainer->AddSlot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		.Padding(DotsPadding)
		[
			SNew(SCheckBox)
			.Style(&DotStyle)
			.IsChecked_Lambda( [this, DotIndex] () -> ECheckBoxState
			{
				return DotChoice == DotIndex ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
			})
			.OnCheckStateChanged_Lambda( [this, DotIndex] (ECheckBoxState InState)
			{
				if (InState == ECheckBoxState::Checked)
				{
					DotChoice = DotIndex;

					ExecuteOnDotSelected();
				}
			})
		];
	}

	if(bShowNavigationButtons)
	{
		DotsContainer->AddSlot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		.Padding(DotsPadding)
		[
			SNew(SButton)
			.ButtonStyle(&NavigateRightButtonStyle)
			.ContentPadding(FMargin(0.0f))
			.OnClicked(this, &SNavigationDots::HandleRight)
			.IsEnabled(this, &SNavigationDots::CanNavigateRight)
		];
	}
}

void SNavigationDots::UpdateDotsPadding() const
{
	if (DotsContainer.IsValid())
	{
		for (int32 SlotIndex = 0; SlotIndex < DotsContainer->NumSlots(); ++SlotIndex)
		{
			if (!DotsContainer->IsValidSlotIndex(SlotIndex))
			{
				continue;
			}

			SHorizontalBox::FSlot& Slot = DotsContainer->GetSlot(SlotIndex);
			Slot.SetPadding(DotsPadding);
		}
	}
}

bool SNavigationDots::CanNavigateLeft() const
{
	return DotChoice > 0;
}

FReply SNavigationDots::HandleLeft()
{
	DotChoice = FMath::Max(0, DotChoice - 1);

	ExecuteOnDotSelected();
	
	return FReply::Handled();
}

bool SNavigationDots::CanNavigateRight() const
{
	return DotChoice < NumberOfDots - 1;
}

FReply SNavigationDots::HandleRight()
{
	DotChoice = FMath::Min(NumberOfDots - 1, DotChoice + 1);
	
	ExecuteOnDotSelected();
	
	return FReply::Handled();
}

void SNavigationDots::ExecuteOnDotSelected() const
{
	if (OnDotSelected.IsBound())
	{
		OnDotSelected.Execute(DotChoice);
	}
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION