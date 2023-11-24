//CODSOFT C++ Programming
//Moksh Pohoja
//Dr. Akhilesh Das Gupta Institute of Technology
//Task 1 Number Guessing game
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    
    srand((unsigned int)(time(0)));

    
    int secretNumber = std::rand() % 100 + 1;

    int userGuess;
    int attempts = 0;
    cout << "Welcome to the Guess the Number game!\n";
    cout << "Try to guess the secret number between 1 and 100.\n\n";

    do {
       
        cout << "Enter your guess: ";
        cin >> userGuess;

        
        if (userGuess < secretNumber) {
            cout << "Too low! Try again.\n";
        } else if (userGuess > secretNumber) {
            cout << "Too high! Try again.\n";
        } else {
            cout << "Congratulations! You guessed the correct number in "<< attempts << " attempts.\n";
        }

        attempts++;

    } while (userGuess != secretNumber);

    return 0;
}
