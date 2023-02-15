#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // seed the random number generator with the current time

    while (true) {
        int numbers[8] = {0};
        string input;
        int numInputs = 0;
        bool validInput = true;

        cout << "Enter 8 non-negative integers: ";
        getline(cin, input);

        // read up to 8 integers from the input
        stringstream ss(input);
        string substring;
        while (getline(ss, substring, ' ') && numInputs < 8) {
            if (substring.empty()) {
                continue;
            }
            try {
                int num = stoi(substring);
                if (num < 0) {
                    validInput = false;
                }
                numbers[numInputs++] = num;
            } catch (invalid_argument&) {
                validInput = false;
            }
        }

        // fill any missing inputs with zeros
        for (int i = numInputs; i < 8; i++) {
            numbers[i] = 0;
        }

        if (!validInput) {
            cout << "Invalid input. Please enter 8 non-negative integers.\n";
            continue;
        }

        // pick a random index to decrease
        int index = rand() % 8;
        while (numbers[index] == 0) {
            index = rand() % 8;
        }

        // decrease the number at the chosen index
        int decrease = rand() % numbers[index] + 1;
        int decreasedNumber = numbers[index] - decrease;
        numbers[index] = decreasedNumber < 0 ? 0 : decreasedNumber;

        // print the updated numbers and the amount decreased
        cout << "We decreased " << numbers[index]+decrease << " by " << decrease << endl;
        for (int i = 0; i < 8; i++) {
            cout << numbers[i] << " ";
        }
        cout << endl;

        // check if all numbers are zero
        bool allZero = true;
        for (int i = 0; i < 8; i++) {
            if (numbers[i] != 0) {
                allZero = false;
                break;
            }
        }
        if (allZero) {
            cout << "You are lost.\n";
            break;
        }
    }

    return 0;
}
