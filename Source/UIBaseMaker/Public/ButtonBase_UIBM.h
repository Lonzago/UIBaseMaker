// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ButtonBase_UIBM.generated.h"


// BUTTON DELEGATES
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnButtonClick);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnButtonRelease);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnButtonHover);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnButtonUnHover);


USTRUCT(BlueprintType)
struct FUIBMButtonConstruct {

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FButtonStyle ButtonStyle;


};

USTRUCT(BlueprintType)
struct FUIBMButtonDelegates {
	
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FOnButtonClick OnClick;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FOnButtonRelease OnRelease;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FOnButtonHover OnHover;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FOnButtonUnHover OnUnHover;
};



UCLASS()
class UIBASEMAKER_API UButtonBase_UIBM : public UUserWidget
{
	GENERATED_BODY()
	

public:

	/*
	* Es necesario crear en el widget un boton con el mismo nombre
	*/
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="UIMB | Button Customization", meta =(BindWidget))
	 class UButton* ButtonMain;

	//----DELEGATES----------//
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "UIMB | Button Customization")
		FOnButtonClick OnClick;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "UIMB | Button Customization")
		FOnButtonRelease OnRelease;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "UIMB | Button Customization")
		FOnButtonHover OnHover;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "UIMB | Button Customization")
		FOnButtonUnHover OnUnHover;
	//----DELEGATES HANDLE----------//
	UFUNCTION()
	void Handle_OnClick();
	UFUNCTION()
	void Handle_OnRelease();
	UFUNCTION()
	void Handle_OnHover();
	UFUNCTION()
	void Handle_OnUnHover();
	//----DELEGATES INTERNALS----------//
	/*Estas funciones estan pensadas para ser llamadas dentro del mismo UserWidget y usar las llamadas*/
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnClickEvent"), Category = "UIMB | Button Customization")
		void OnClick_Internal();
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnReleaseEvent"), Category = "UIMB | Button Customization")
		void OnRelease_Internal();
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnHoverEvent"), Category = "UIMB | Button Customization")
		void OnHover_Internal();
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnUnHoverEvent"), Category = "UIMB | Button Customization")
		void OnUnHover_Internal();


	//----SET STYLES----------//

	/*Can Override ButtonStyles*/
	UFUNCTION(BlueprintCallable, Category = "UIMB | Button Customization")
		void OverrideButtonStyle(const FButtonStyle& OverButtonStyle);
	/*Get ButtoMain Style*/
	UFUNCTION(BlueprintPure, Category = "UIMB | Button Customization")
		FButtonStyle GetButtonStyle()const;




protected:
	virtual void NativePreConstruct() override;

};
