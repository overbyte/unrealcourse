// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"


void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetHiddenWord();
    DisplayWelcomeMessage();
}

void UBullCowCartridge::DisplayWelcomeMessage()
{
    PrintLine(TEXT("Welcome to the Bull Cow Game."));
    PrintLine(TEXT("Press Tab to interact."));
    PrintLine(TEXT("I'm thinking of a 5 letter word")); // TODO: fix magic number
}

void UBullCowCartridge::SetHiddenWord()
{
    HiddenWord = TEXT("amiga");    
}


void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    if (Input == HiddenWord) 
    {
        PrintLine("YOU GOT IT!");
    }
    else
    {
        PrintLine("Nope. That wasn't it");
    }
}
