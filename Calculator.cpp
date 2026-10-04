#include <iostream>

// Function declarations
void displayMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {
    int choice;
    double num1, num2;

    do {
        displayMenu();
        std::cin >> choice;

        // Exit immediately if the user chooses 5
        if (choice == 5) {
            std::cout << "Exiting calculator. Goodbye!\n";
            break;
        }

        // Validate menu choices 1-4
        if (choice < 1 || choice > 5) {
            std::cout << "Invalid choice! Please select a number between 1 and 5.\n\n";
            continue;
        }

        // Gather numbers for valid operations
        std::cout << "Enter first number: ";
        std::cin >> num1;
        std::cout << "Enter second number: ";
        std::cin >> num2;

        // Perform calculation based on choice
        switch (choice) {
            case 1:
                std::cout << "Result: " << add(num1, num2) << "\n\n";
                break;
            case 2:
                std::cout << "Result: " << subtract(num1, num2) << "\n\n";
                break;
            case 3:
                std::cout << "Result: " << multiply(num1, num2) << "\n\n";
                break;
            case 4:
                // Division logic handles safety inside the function
                if (num2 == 0) {
                    std::cout << "Error: Division by zero is undefined.\n\n";
                } else {
                    std::cout << "Result: " << divide(num1, num2) << "\n\n";
                }
                break;
        }

    } while (choice != 5);

    return 0;
}

// Function implementations
void displayMenu() {
    std::cout << "=== C++ Calculator Menu ===\n";
    std::cout << "1. Addition (+)\n";
    std::cout << "2. Subtraction (-)\n";
    std::cout << "3. Multiplication (*)\n";
    std::cout << "4. Division (/)\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter choice (1-5): ";
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}
