// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"


void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    InitGame();
    PrintLine(TEXT("The hidden word is %s"), *HiddenWord);
}

void UBullCowCartridge::InitGame()
{
    currentLives = START_LIVES;
    HiddenWord = TEXT("amiga");
    bIsGameOver = false;

    PrintWelcomeMessage();
    AskForGuess();
}

void UBullCowCartridge::PrintWelcomeMessage()
{
    PrintLine(TEXT("Welcome to the Bull Cow Game."));
    PrintLine(TEXT("Press Tab to interact."));
}

void UBullCowCartridge::AskForGuess()
{
    PrintLine(TEXT("I'm thinking of a %i letter word"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives left"), currentLives);
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    // if game is over, clear screen and setup game
    if (bIsGameOver)
    {
         InitGame();
    }
    // else check if guess is isogram
    else if (!IsGuessIsogram(Input)) 
    {
        PrintLine(TEXT("%s isn't an isogram. Try again"), *Input);
        return;
    }
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

    else if (Input == HiddenWord) 
    {
        PrintLine(TEXT("YOU GOT IT!"));
        EndGame();
    }
    else if (Input != "")
    {
        --currentLives;
        if (currentLives > 0) 
        {
            PrintLine(TEXT("Nope. That wasn't it. Try again - you have %i lives left"), currentLives);
        }
        else
        {
            PrintLine(TEXT("You're out of lives"));
            EndGame();
        }
    }
}

bool UBullCowCartridge::IsGuessIsogram(FString Guess)
{
    if (Guess.Len() == HiddenWord.Len()) 
    {
        return true;
    }
    else 
    {
        return false;
    }
}

void UBullCowCartridge::EndGame()
{
    bIsGameOver = true;
    PrintLine("Thanks for playing. \nPress Enter to play again");
}
