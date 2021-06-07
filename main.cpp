#include <iostream>
#include "generator.hpp"

using namespace std;

bool input(string message);

int main() {

    // just initiating variables
    int length;

    bool use_numbers;
    bool use_special_chars;
    bool capitalize;

    // Getting input from user
    cout << "Enter pass length: ";
    cin >> length;
    cout << endl;

    use_numbers = input("Use numbers?");
    use_special_chars = input("Use special characters?");
    capitalize = input("Use random capitalization");

    cout << Generator::generatePassword(length, use_numbers, use_special_chars, capitalize);

    return 0;

}

bool input(string message) {

    string input;

    cout << message << " (yes/no): ";
    cin >> input;
    cout << endl;

    if (input == "yes") {
        return true;

    } else if (input == "no") {
        return false;

    } else {
        cout << "Invalid input" << endl;
    }

}
