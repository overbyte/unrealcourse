// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"


void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    InitGame();
    PrintWelcomeMessage();
    // Ask for guess
}

void UBullCowCartridge::InitGame() 
{
    currentLives = START_LIVES;
    HiddenWord = TEXT("amiga");    
}

void UBullCowCartridge::PrintWelcomeMessage()
{
    PrintLine(TEXT("Welcome to the Bull Cow Game."));
    PrintLine(TEXT("Press Tab to interact."));
}

void UBullCowCartridge::AskForGuess()
{
    PrintLine(TEXT("I'm thinking of a 5 letter word")); // TODO: fix magic number
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    // check if guess is isogram
    // prompt to guess again
    // check guess is correct
    // if yes, print the win message
    // otherwise, decrement lives
    // check we still have a life
    // if yes, ask for guess
    // otherwise, print lose message
    // ask to play again
    // if yes, start again
    // otherwise quit

    if (Input == HiddenWord) 
    {
        PrintLine("YOU GOT IT!");
    }
    else
    {
        PrintLine("Nope. That wasn't it");
    }
}
