#include <iostream>

int OutputIntro();

int main() 
{
    OutputIntro();
    OutputChallenge();
    return 0; 
}

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

int OutputChallenge()
{
    const int a = 3;
    const int b = 4;
    const int c = 9;

    const int sum = a + b + c;
    const int product = a * b * c;

    std::cout << sum << std::endl;
    std::cout << product << std::endl;
}
