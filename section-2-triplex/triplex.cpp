#include <iostream>

int OutputIntro();
int OutputChallenge();
int InputPlayerGuess();

int main() 
{
    OutputIntro();
    OutputChallenge();
    InputPlayerGuess();

    return 0; 
}

// output a static intro
int OutputIntro()
{
    std::cout << "Only one more step to do!" << std::endl;
    std::cout << "You've avoided all the booby traps and security ";
    std::cout << "so there's just one more thing to do - ";
    std::cout << "hack the terminal! " << std::endl;
    std::cout << "It's all down to you!" << std::endl;
    std::cout << "Enter the correct codes..." << std::endl;

    return 0;
}


// output the challenge
int OutputChallenge()
{
    const int CodeA = 3;
    const int CodeB = 4;
    const int CodeC = 9;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "There are 3 numbers in the code" << std::endl;
    std::cout << "The numbers add up to " << CodeSum << std::endl;
    std::cout << "The numbers multiply to " << CodeProduct << std::endl;

    return 0;
}

// get player input
int InputPlayerGuess()
{
    int GuessA, GuessB, GuessC;

    std::cout << "Enter your 3 numbers" << std::endl;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;

    std::cout << "You entered " << GuessA << ", " << GuessB << ", " << GuessC << std::endl;
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    std::cout << "The numbers add up to " << GuessSum << std::endl;
    std::cout << "The numbers multiply to " << GuessProduct << std::endl;

    return 0;
}
