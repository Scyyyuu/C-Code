#include <iostream>
#include <cstdlib> // Required for rand() and srand()
#include <ctime>   // Required for time()

int main() {
    // 1. Seed the random number generator so it's different every time you play
    std::srand(static_cast<unsigned int>(std::time(0)));
    
    // 2. Generate a random number between 1 and 100
    int secret_number = (std::rand() % 100) + 1;
    int user_guess = 0;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "I have chosen a number between 1 and 100. Try to guess it!\n\n";

    // 3. Keep looping until the player guesses the correct number
    while (user_guess != secret_number) {
        std::cout << "Enter your guess: ";
        std::cin >> user_guess;
        attempts++; // Increment the number of tries

        // 4. Provide feedback to the player using conditionals
        if (user_guess > secret_number) {
            std::cout << "Too high! Try a lower number.\n\n";
        } else if (user_guess < secret_number) {
            std::cout << "Too low! Try a higher number.\n\n";
        } else {
            std::cout << "🎉 Congratulations! You guessed the number " << secret_number << "!\n";
            std::cout << "It took you " << attempts << " attempts.\n";
        }
    }

    return 0; // Signals successful program completion
}

