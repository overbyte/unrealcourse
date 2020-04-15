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

void UBullCowCartridge::PrintWelcomeMessage() const
{
    PrintLine(TEXT("Welcome to the Bull Cow Game."));
    PrintLine(TEXT("Press Tab to interact."));
}

void UBullCowCartridge::AskForGuess() const
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
    // add test to see if input is empty (user has just pressed enter)
    if (Guess == "")
    {
        return;
    }

    // check guess is correct
    if (Guess == HiddenWord)
    {
        // if yes, print the win message
        PrintLine(TEXT("YOU GOT IT!"));
        EndGame();
        return;
    }

    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("%s isn't the correct length. Try again."), *Guess);
        return;
    }

    if (!IsIsogram(Guess))
    {
        // prompt to guess again
        PrintLine(TEXT("%s isn't an isogram. Try again"), *Guess);
        return;
    }

    // otherwise, decrement lives
    --Lives;

    // check we still have a life
    if (Lives > 0)
    {
        PrintLine(TEXT("Nope. That wasn't it. Try again - you have %i lives left"), Lives);
        PrintLine(TEXT("The hidden word was %s"), *HiddenWord);
        return;
    }

    // otherwise, print lose message
    PrintLine(TEXT("Oh Noez! You're out of lives"));
    EndGame();
}

bool UBullCowCartridge::IsIsogram(FString Word) const
{
    // TODO : doesn't really check for isogram
    return (Guess.Len() == HiddenWord.Len());
    return true;
}

void UBullCowCartridge::EndGame()
{
    // if yes, ask for guess
    // ask to play again
    // if yes, start again
    // otherwise quit
    bIsGameOver = true;
    PrintLine(TEXT("Thanks for playing."));
    PrintLine(TEXT("\n\nPress Enter to play again"));
}
