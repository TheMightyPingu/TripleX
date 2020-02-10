// Import IoStream Library
#include <iostream>

// Import ctime Library That Helps Manipulate Time and Date Information
#include <ctime>

// Function To Print Game Introduction.
void PrintIntroduction(int Difficulty)
{
    // Print Welcome Messages To The Terminal.
    std::cout << "\n\nYou Are A Secret Agent Breaking Into A Level " << Difficulty; 
    std::cout << " Secure Server Room...\n";
    std::cout << "Enter The Correct Code To Continue...\n";
}


// Function To Play Game
bool PlayGame(int Difficulty) 
{
    // Prints Game Introduction.
    PrintIntroduction(Difficulty);

    // Store Code Numbers.
    const int CodeA = rand() % Difficulty + (Difficulty * 5);
    const int CodeB = rand() % Difficulty + (Difficulty * 5);
    const int CodeC = rand() % Difficulty + (Difficulty * 5);
    
    // Compute Sum And Product Of Code Numbers.
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print Sum And Product Of The Codes. 
    
    std::cout << "\n+ There Are 3 Numbers In The Code";
    std::cout << "\n+ The Numbers Add-Up To: " << CodeSum;
    std::cout << "\n+ The Numbers Multiply To Give: " << CodeProduct << std::endl;
    std::cout << std::endl;

    // Store And Input Guesses.
    int GuessA, GuessB, GuessC;
    std::cout << "Enter The Code: ";
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "You Guessed: " << GuessA << ", " << GuessB << ", and " << GuessC << std::endl;

    // Store The Sum And Product Of The Guesses.
    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    // Check Guesses and Grant Access If They Are Correct.
    if (GuessSum == CodeSum && GuessProduct == CodeProduct) 
    {
        std::cout << "\n*** ACCESS GRANTED TO LEVEL " << Difficulty << " ***" << std::endl;
        return true;
    }

    // Deny Access If Guesses Are Wrong.
    else    
    {
        std::cout << "\n*** ACCESS DENIED! CAREFUL AGENT! TRY AGAIN! ***\n";
        return false;
    }

}
 
int main() 
{
    // Create New Random Sequence Based On Time Of Day
    srand(time(NULL));

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    // Loop Game Until All Levels Are Completed
    while (LevelDifficulty <= MaxDifficulty) 
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears Any Errors
        std::cin.ignore(); // Discards The Buffer

        if (bLevelComplete) // Same As Saying bLevelComplete == true
        {   
            // Increase Level Difficulty
            LevelDifficulty++;
        }
        
    }
    std::cout << "\n*** GREAT WORK AGENT! NOW GET OUT OF HERE! ***\n ";
    // Exit Program When Return Value Is 0. 
    return 0;

}