// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to the Bull Cow Game."));
    PrintLine(TEXT("Press Tab to interact."));
    PrintLine(TEXT("I'm thinking of a 5 letter word"));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    const FString HiddenWord = TEXT("amiga");

    if (Input == HiddenWord) 
    {
        PrintLine("YOU GOT IT!");
    }
    else
    {
        PrintLine("Nope. That wasn't it");
    }
}
