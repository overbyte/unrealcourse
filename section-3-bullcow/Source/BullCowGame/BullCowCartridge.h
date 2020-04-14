// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;

	// Your declarations go below!
	private:
    const int32 START_LIVES = 5;
    FString HiddenWord;
    int32 currentLives;

    void InitGame();
    void AskForGuess();
    void PrintWelcomeMessage();
    bool IsGuessIsogram(FString Guess);
};
