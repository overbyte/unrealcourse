#include <iostream>

void PlayGame();
void OutputIntro();
void OutputChallenge();
void InputPlayerGuess();
void TestWinCondition();

const int CodeA = 3;
const int CodeB = 4;
const int CodeC = 9;
const int CodeSum = CodeA + CodeB + CodeC;
const int CodeProduct = CodeA * CodeB * CodeC;

int GuessA, GuessB, GuessC;
int GuessSum, GuessProduct;

int main() 
{
    PlayGame();
    return 0; 
}

void PlayGame()
{
    OutputIntro();
    InputPlayerGuess();
    TestWinCondition();
}

// output a static intro
void OutputIntro()
{
    std::cout << "Only one more step to do!\n";
    std::cout << "You've avoided all the booby traps and security ";
    std::cout << "so there's just one more thing to do - ";
    std::cout << "hack the terminal! \n";
    std::cout << "It's all down to you!\n\n";
    std::cout << "There are 3 numbers in the code\n";
    std::cout << "The numbers add up to " << CodeSum << std::endl;
    std::cout << "The numbers multiply to " << CodeProduct << std::endl;
}

// get player input
void InputPlayerGuess()
{
    std::cout << "Enter your 3 numbers\n";
    std::cin >> GuessA >> GuessB >> GuessC;

    std::cout << "You entered " << GuessA << ", " << GuessB << ", " << GuessC << std::endl;
    GuessSum = GuessA + GuessB + GuessC;
    GuessProduct = GuessA * GuessB * GuessC;

    std::cout << "The numbers add up to " << GuessSum << std::endl;
    std::cout << "The numbers multiply to " << GuessProduct << std::endl;
}

// check if the player got it right
void TestWinCondition() {
    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        std::cout << "Congratulations! You got it right!\n";
    } else {
        std::cout << "That wasn't it - Everybody dies\n";
    }
}
