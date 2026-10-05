// Password Strength Checker - starter file
// Compile: g++ -std=c++17 password_checker.cpp -o password_checker
// Run:     password_checker
//
// Fill in every TODO. Read the HINT lines only if you get stuck.

#include <iostream>
#include <string>
#include <cctype>   // isupper, islower, isdigit, ispunct
using namespace std;

// TODO: return true if the password has at least one uppercase letter.
// HINT: loop through each character and use isupper(c)
bool hasUpper(const string &password) {
    return false;
}

// TODO: return true if the password has at least one lowercase letter.
bool hasLower(const string &password) {
    return false;
}

// TODO: return true if the password has at least one digit.
bool hasDigit(const string &password) {
    return false;
}

// TODO: return true if the password has at least one symbol (like ! @ # $).
// HINT: ispunct(c)
bool hasSymbol(const string &password) {
    return false;
}

// TODO: count how many rules the password passes (0 to 5).
// Rules: length >= 8, upper, lower, digit, symbol
// HINT: start with int score = 0; and add 1 for each rule that passes.
int calculateScore(const string &password) {
    return 0;
}

// TODO: turn the score into a label: "Weak", "Medium", or "Strong".
// Decide your own cutoffs. Which scores should count as Weak?
string getStrength(int score) {
    return "";
}

int main() {
    string password;
    cout << "Enter a password: ";
    cin >> password;

    // TODO: calculate the score and print the strength.
    // TODO (bonus): print which rules are missing, e.g.
    //   "Add an uppercase letter" or "Use at least 8 characters".

    return 0;
}