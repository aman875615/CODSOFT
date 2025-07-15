#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    cout << "===============================================================" << endl;
    cout << "              Welcome to the NUMBER Guessing Game!             " << endl;
    cout << "===============================================================" << endl << endl;

    // Seed for random number generation
    srand(time(0));

    int modeChoice;

    cout << "Select Difficulty:" << endl;
    cout << "1 -> Easy (1 to 10)" << endl;
    cout << "2 -> Normal (1 to 100)" << endl;
    cout << "3 -> Hard (1 to 1000)" << endl;
    cout << "Any other key to quit." << endl;
    cin >> modeChoice;

    while (modeChoice == 1 || modeChoice == 2 || modeChoice == 3) {
        int targetNumber;
        int guess;
        int maxRange;
        int attempts = 0;

        // Set the range based on difficulty
        if (modeChoice == 1) {
            maxRange = 10;
            cout << "\nYou're in EASY mode! Guess a number between 1 and 10." << endl;
        } else if (modeChoice == 2) {
            maxRange = 100;
            cout << "\nYou're in NORMAL mode! Guess a number between 1 and 100." << endl;
        } else {
            maxRange = 1000;
            cout << "\nYou're in HARD mode! Guess a number between 1 and 1000." << endl;
        }

        // Generate random number
        targetNumber = rand() % maxRange + 1;

        // Start guessing loop
        do {
            cout << "Enter your guess: ";
            cin >> guess;
            attempts++;

            if (guess < targetNumber) {
                cout << "Too low! Try a higher number." << endl;
            } else if (guess > targetNumber) {
                cout << "Too high! Try a lower number." << endl;
            }

        } while (guess != targetNumber);

        cout << "Congratulations! You guessed it right. The number was " << targetNumber << "." << endl;
        cout << "It took you " << attempts << " attempt(s)." << endl;

        // Ask for next round
        cout << "\nWant to play again? Choose difficulty:" << endl;
        cout << "1 -> Easy | 2 -> Normal | 3 -> Hard | Any other key to exit" << endl;
        cin >> modeChoice;
    }

    cout << "\nThanks for playing! Have a great day! " << endl;
    return 0;
}
