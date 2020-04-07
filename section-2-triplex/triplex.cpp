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
    int a = 3;
    int b = 4;
    int c = 9;

    int sum = a + b + c;
    int product = a * b * c;

    std::cout << sum << std::endl;
    std::cout << product << std::endl;
}
