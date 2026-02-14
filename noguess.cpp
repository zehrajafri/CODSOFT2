#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int randomNumber, userGuess;
    int attempts = 0;

    // Seed the random number generator
    srand(time(0));

    // Generate random number between 1 and 100
    randomNumber = rand() % 100 + 1;

    cout << "Welcome to the Number Guessing Game.\n";
    cout << "I have selected a number between 1 and 100.\n";
    cout << "Try to guess it.\n";

    do {
        cout << "\nEnter your guess: ";
        cin >> userGuess;
        attempts++;

        if (userGuess > randomNumber) {
            cout << "Too high. Try a smaller number.";
        }
        else if (userGuess < randomNumber) {
            cout << "Too low. Try a bigger number.";
        }
        else {
            cout << "\nCongratulations. You guessed the correct number.";
            cout << "\nIt took you " << attempts << " attempt(s).";
        }

    } while (userGuess != randomNumber);

    cout << "\nThank you for playing.\n";

    return 0;
}