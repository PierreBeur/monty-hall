#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    int totalSimulations;
    int switchWins = 0;
    int stayWins = 0;

    cout << "Monty Hall Paradox Simulation\n";

    // Input validation loop
    bool valid = false;
    while (!valid) {
        cout << "Enter the number of simulations: ";
        if (cin >> totalSimulations && totalSimulations > 0) {
            valid = true; // Input is valid, exit the loop
        } else {
            cout << "Invalid input. Please enter a positive integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Seed the random number generator
    srand(time(0));

    for (int i = 0; i < totalSimulations; ++i) {
        // Randomly place the prize behind one of the three doors
        int prizeDoor = rand() % 3;

        // Player's initial choice
        int playerChoice = rand() % 3;

        // Monty Hall reveals a door without the prize
        int revealedDoor;
        do {
            revealedDoor = rand() % 3;
        } while (revealedDoor == prizeDoor || revealedDoor == playerChoice);

        // Player chooses whether to switch doors
        int switchChoice;
        do {
            switchChoice = rand() % 3;
        } while (switchChoice == playerChoice || switchChoice == revealedDoor);

        // Determine the outcome
        if (switchChoice == prizeDoor) {
            switchWins++;
        } else if (playerChoice == prizeDoor) {
            stayWins++;
        }
    }

    cout << "Results after " << totalSimulations << " simulations:\n";
    cout << "Switching wins: " << switchWins << " (" << (double)switchWins / totalSimulations * 100 << "%)\n";
    cout << "Staying wins: " << stayWins << " (" << (double)stayWins / totalSimulations * 100 << "%)\n";

    return 0;
}
