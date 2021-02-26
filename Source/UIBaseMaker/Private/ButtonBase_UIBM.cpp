// Fill out your copyright notice in the Description page of Project Settings.


#include "ButtonBase_UIBM.h"
#include "Components/Button.h"



void UButtonBase_UIBM::Handle_OnClick()
{
	OnClick.Broadcast();
	OnClick_Internal();
}

void UButtonBase_UIBM::Handle_OnRelease()
{
	OnRelease.Broadcast();
	OnRelease_Internal();
}

void UButtonBase_UIBM::Handle_OnHover()
{
	OnHover.Broadcast();
	OnHover_Internal();
}

void UButtonBase_UIBM::Handle_OnUnHover()
{
	OnUnHover.Broadcast();
	OnUnHover_Internal();
}

void UButtonBase_UIBM::OverrideButtonStyle(const FButtonStyle& OverButtonStyle)
{
	if (ButtonMain!=nullptr)
	{
		ButtonMain->SetStyle(OverButtonStyle);
	}
}

FButtonStyle UButtonBase_UIBM::GetButtonStyle() const
{
	FButtonStyle OutStyle;
	if (ButtonMain != nullptr)
	{
		OutStyle = ButtonMain->WidgetStyle;
	}
	return OutStyle;
}

void UButtonBase_UIBM::NativePreConstruct()
{
	Super::NativePreConstruct();
	
	if (ButtonMain != nullptr)
	{

		// BIND BUTTONS DELEGATE
		ButtonMain->OnClicked.AddDynamic(this, &UButtonBase_UIBM::Handle_OnClick);
		ButtonMain->OnReleased.AddDynamic(this, &UButtonBase_UIBM::Handle_OnRelease);
		ButtonMain->OnHovered.AddDynamic(this, &UButtonBase_UIBM::Handle_OnHover);
		ButtonMain->OnUnhovered.AddDynamic(this, &UButtonBase_UIBM::Handle_OnUnHover);

		//TODOGon : Hacer que cambie tambien el stylo

	}

}
