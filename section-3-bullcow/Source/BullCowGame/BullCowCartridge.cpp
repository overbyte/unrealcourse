// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"
#include <ctime>


void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    InitGame();
    PrintLine(TEXT("The hidden word is %s"), *HiddenWord);
}

void UBullCowCartridge::InitGame()
{
    HiddenWord = GetHiddenWord();
    Lives = HiddenWord.Len();
    bIsGameOver = false;

    PrintWelcomeMessage();
    AskForGuess();
}

FString UBullCowCartridge::GetHiddenWord() const
{
    TArray<FString> ValidWords = GetValidWords(Words);

    // seed the RNG
    //srand(time(NULL));
    //const int32 RandomIndex = rand() % ValidWords.Num();
    return ValidWords[FMath::RandRange(0, ValidWords.Num())];
}

TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& WordList) const
{
    TArray<FString> ValidWords;

    for (FString Word : WordList)
    {
        if (Word.Len() >= MIN_WORD_SIZE && 
            Word.Len() <= MAX_WORD_SIZE && 
            IsIsogram(Word))
        {
            ValidWords.Emplace(Word);
        }
    }

    return ValidWords;
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

void UBullCowCartridge::ProcessGuess(const FString& Guess)
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
        PrintLine(TEXT("%s has duplicate letters. Try again"), *Guess);
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
    PrintLine(TEXT("Oh Noez! You're out of lives"));
    PrintLine(TEXT("The hidden word was %s"), *HiddenWord);
    EndGame();
}

bool UBullCowCartridge::IsIsogram(const FString& Word) const
{
    //TCHAR WordDict[] = Word;
    // for each character in guess
    // note: There is a null character at the end of an FString called \0
    for (int32 Index = 0; Index < Word.Len(); ++Index)
    {
        for (int32 Comparison = Index + 1; Comparison < Word.Len(); ++Comparison)
        {
            if (Word[Index] == Word[Comparison])
            {
                return false;
            }
        }
        // if the character is in our guess dictionary
        // the guess is not an isogram
        // else save the character to the dictionary
    }
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
