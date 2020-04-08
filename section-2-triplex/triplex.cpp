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


    std::cout << "                      :::!~!!!!!:.\n";
    std::cout << "                  .xUHWH!! !!?M88WHX:.\n";
    std::cout << "                .X*#M@$!!  !X!M$$$$$$WWx:.\n";

    std::cout << "               :!!!!!!?H! :!$!$$$$$$$$$$8X:\n";

    std::cout << "              !!~  ~:~!! :~!$!#$$$$$$$$$$8X:\n";

    std::cout << "             :!~::!H!<   ~.U$X!?R$$$$$$$$MM!\n";

    std::cout << "             ~!~!!!!~~ .:XW$$$U!!?$$$$$$RMM!\n";

    std::cout << "               !:~~~ .:!M\"T#$$$$WX??#MRRMMM!\n";

    std::cout << "               ~?WuxiW*`   `\"#$$$$8!!!!??!!!\n";

    std::cout << "             :X- M$$$$       `\"T#$T~!8$WUXU~\n";

    std::cout << "            :%`  ~#$$$m:        ~!~ ?$$$$$$\n";

    std::cout << "          :!`.-   ~T$$$$8xx.  .xWW- ~\"\"##*\"\n";

    std::cout << ".....   -~~:<` !    ~?T#$$@@W@*?$$      /`\n";

    std::cout << "W$@@M!!! .!~~ !!     .:XUW$W!~ `\"~:    :\n";

    std::cout << "#\"~~`.:x%`!!  !H:   !WM$$$$Ti.: .!WUn+!`\n";

    std::cout << ":::~:!!`:X~ .: ?H.!u \"$$$B$$$!W:U!T$$M~\n";

    std::cout << ".~~   :X@!.-~   ?@WTWo(\"*$$$W$TH$! `\n";

    std::cout << "Wi.~!X$?!-~    : ?$$$B$Wu(\"**$RM!\n";

    std::cout << "$R@i.~~ !     :   ~$$$$$B$$en:``\n";

    std::cout << "?MXT@Wx.~    :     ~\"##*$$$$M~\n";

    std::cout << "Only one more step to go!\n";
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
