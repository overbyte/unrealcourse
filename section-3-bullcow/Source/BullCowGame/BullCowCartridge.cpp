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
    HiddenWord = TEXT("amiga");
    Lives = HiddenWord.Len();
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
    PrintLine(TEXT("You have %i lives left"), Lives);
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    if (bIsGameOver)
    {
         InitGame();
    }
    else
    {
        ProcessGuess(Input);
    } 
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    // check guess is correct
    if (Guess == HiddenWord)
    {
        // if yes, print the win message
        PrintLine(TEXT("YOU GOT IT!"));
        EndGame();
        return;
    }

    if (!IsGuessIsogram(Guess))
    {
        // prompt to guess again
        PrintLine(TEXT("%s isn't an isogram. Try again"), *Guess);
        return;
    }

    // add test to see if input is empty (user has just pressed enter)
    if (Guess == "")
    {
        return;
    }

    // otherwise, decrement lives
    --Lives;
    // check we still have a life
    if (Lives > 0)
    {
        PrintLine(TEXT("Nope. That wasn't it. Try again - you have %i lives left"), Lives);
        return;
    }

    // otherwise, print lose message
    PrintLine(TEXT("You're out of lives"));
    EndGame();
}

bool UBullCowCartridge::IsGuessIsogram(FString Guess)
{
    return (Guess.Len() == HiddenWord.Len());
}

void UBullCowCartridge::EndGame()
{
    // if yes, ask for guess
    // ask to play again
    // if yes, start again
    // otherwise quit
    bIsGameOver = true;
    PrintLine("Thanks for playing. \nPress Enter to play again");
}
