// 1. HEADER FILES AND NAMESPACES
#include <iostream>   // Required for input/output streams (cin, cout)
#include <string>     // Required to use the 'string' data type

using namespace std;  // Allows us to use standard library names without typing 'std::'

// 2. MAIN FUNCTION (The entry point of every C++ program)
int main() {
    
    // ==========================================
    // 3. COMMENTS & BASIC OUTPUT
    // ==========================================
    // This is a single-line comment. The compiler ignores it.
    
    /* This is a multi-line comment.
       It can span across multiple lines. */
       
    // Printing text using cout and the insertion operator (<<)
    cout << "Welcome to C++ Basics!" << endl; // 'endl' inserts a newline and flushes the buffer
    cout << "Line 2 text.\n";                 // '\n' is an alternative, faster way to jump to a new line


    // ==========================================
    // 4. DATA TYPES & VARIABLES
    // ==========================================
    // Syntax: type variableName = value;
    
    int age = 25;                           // int: stores whole numbers (integers)
    double pi = 3.14159;                    // double: stores double-precision floating-point numbers (decimals)
    float temperature = 98.6f;              // float: single-precision decimal (requires 'f' suffix)
    char grade = 'A';                       // char: stores a single character (must use single quotes '')
    string name = "Alex";                   // string: stores a sequence of text characters (must use double quotes "")
    bool isCodingFun = true;                // bool: stores boolean values (true or false)

    // Constant variable: its value cannot be changed after declaration
    const int DAYS_IN_WEEK = 7; 


    // ==========================================
    // 5. COMBINING OUTPUT WITH VARIABLES
    // ==========================================
    cout << "\n--- Student Info ---" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << " years old" << endl;
    cout << "GPA Grade: " << grade << endl;
    
    // Printing a boolean variable outputs 1 for true, 0 for false
    cout << "Is coding fun? " << isCodingFun << " (1 means True)" << endl; 


    // ==========================================
    // 6. OPERATORS
    // ==========================================
    int num1 = 10;
    int num2 = 3;

    // A. Arithmetic Operators
    int sum = num1 + num2;                  // Addition (+)
    int diff = num1 - num2;                 // Subtraction (-)
    int product = num1 * num2;              // Multiplication (*)
    int quotient = num1 / num2;             // Division (/) -> Integer division truncates decimals (10/3 = 3)
    int remainder = num1 % num2;            // Modulo (%) -> Finds the remainder of division (10%3 = 1)

    cout << "\n--- Arithmetic Results ---" << endl;
    cout << "Sum: " << sum << ", Remainder: " << remainder << endl;

    // B. Assignment & Compound Operators
    int score = 100;
    score += 5;                             // Equivalent to: score = score + 5; (score becomes 105)
    score++;                                // Increment operator: adds 1 to score (score becomes 106)
    score--;                                // Decrement operator: subtracts 1 from score (score becomes 105)


    // ==========================================
    // 7. USER INPUT (cin)
    // ==========================================
    int userNumber;
    cout << "\n--- User Input ---" << endl;
    cout << "Enter your favorite integer: ";
    
    // Reads input from the keyboard using the extraction operator (>>)
    cin >> userNumber; 
    
    cout << "Awesome! Your favorite number multiplied by 2 is: " << (userNumber * 2) << endl;


    // 8. RETURN STATEMENT
    return 0; // Signals to the operating system that the program executed successfully
}
