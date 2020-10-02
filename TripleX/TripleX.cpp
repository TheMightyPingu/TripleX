// Import IoStream Library
#include <iostream>

// Import ctime Library That Helps Manipulate Time and Date Information
#include <ctime>
using namespace std; 

// Function To Play Game
bool PlayGame(int Difficulty) 
{
    // Prints Game Introduction.
    cout << "\n\nYou Are A Secret Agent Breaking Into A Level " << Difficulty; 
    cout << " Secure Server Room...\n";
    cout << "Enter The Correct Code To Continue...\n";
    // Store Code Numbers.
    const int CodeA = rand() % Difficulty + Difficulty*2;
    const int CodeB = rand() % Difficulty + Difficulty*2;
    const int CodeC = rand() % Difficulty + Difficulty*2;
    
    // Compute Sum And Product Of Code Numbers.
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print Sum And Product Of The Codes. 
    
    cout << "\n+ There Are 3 Numbers In The Code";
    cout << "\n+ The Numbers Add-Up To: " << CodeSum;
    cout << "\n+ The Numbers Multiply To Give: " << CodeProduct << endl;
    cout << endl;

    // Store And Input Guesses.
    int GuessA, GuessB, GuessC;
    cout << "Enter The Code: ";
    cin >> GuessA >> GuessB >> GuessC;
    cout << "You Guessed: " << GuessA << ", " << GuessB << ", and " << GuessC << endl;

    // Store The Sum And Product Of The Guesses.
    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    // Check Guesses and Grant Access If They Are Correct.
    if (GuessSum == CodeSum && GuessProduct == CodeProduct) 
    {
        cout << "\n*** ACCESS GRANTED TO LEVEL " << Difficulty << " ***" << endl;
        return true;
    }

    // Deny Access If Guesses Are Wrong.
    else    
    {
        cout << "\n*** ACCESS DENIED! CAREFUL AGENT! TRY AGAIN! ***\n";
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
        cin.clear(); // Clears Any Errors
        cin.ignore(); // Discards The Buffer

        if (bLevelComplete) // Same As Saying bLevelComplete == true
        {   
            // Increase Level Difficulty
            LevelDifficulty++;
        }
        
    }
    cout << "\n*** GREAT WORK AGENT! NOW GET OUT OF HERE! ***\n ";
    // Exit Program When Return Value Is 0. 
    return 0;

}