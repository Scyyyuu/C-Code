// ============================================================
//  C++ FUNDAMENTALS SHOWCASE
//  Compile: g++ -std=c++17 cpp_fundamentals.cpp -o fundamentals
//  Run:     ./fundamentals
// ============================================================

#include <iostream>     // input / output (cin, cout)
#include <string>       // std::string
#include <vector>       // dynamic arrays
#include <map>          // key-value pairs
#include <algorithm>    // sort, find, etc.
#include <stdexcept>    // exceptions
#include <memory>       // smart pointers

using namespace std;

// ------------------------------------------------------------
// 1. CONSTANTS, ENUMS, AND STRUCTS (declared globally)
// ------------------------------------------------------------
const double PI = 3.14159;

enum Grade { FAIL, PASS, HONORS };

struct Point {
    int x;
    int y;
};

// ------------------------------------------------------------
// 2. FUNCTIONS
// ------------------------------------------------------------
int add(int a, int b) {                 // basic function
    return a + b;
}

double add(double a, double b) {        // function overloading
    return a + b;
}

int power(int base, int exp = 2) {      // default argument
    int result = 1;
    for (int i = 0; i < exp; i++) result *= base;
    return result;
}

void swapByRef(int &a, int &b) {        // pass by reference
    int temp = a;
    a = b;
    b = temp;
}

int factorial(int n) {                  // recursion
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

template <typename T>                   // template (generic function)
T maxOf(T a, T b) {
    return (a > b) ? a : b;
}

// ------------------------------------------------------------
// 3. CLASSES: encapsulation, inheritance, polymorphism
// ------------------------------------------------------------
class Shape {
protected:
    string name;
public:
    Shape(string n) : name(n) {}                  // constructor
    virtual double area() const = 0;              // pure virtual (abstract)
    virtual void describe() const {
        cout << name << " with area " << area() << endl;
    }
    virtual ~Shape() {}                           // virtual destructor
};

class Circle : public Shape {                     // inheritance
private:
    double radius;
public:
    Circle(double r) : Shape("Circle"), radius(r) {}
    double area() const override { return PI * radius * radius; }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : Shape("Rectangle"), width(w), height(h) {}
    double area() const override { return width * height; }
};

class BankAccount {                               // encapsulation
private:
    double balance;
public:
    BankAccount(double initial = 0) : balance(initial) {}

    void deposit(double amount) {
        if (amount <= 0) throw invalid_argument("Deposit must be positive");
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount > balance) throw runtime_error("Insufficient funds");
        balance -= amount;
    }

    double getBalance() const { return balance; } // getter
};

// ------------------------------------------------------------
// MAIN
// ------------------------------------------------------------
int main() {

    // --------------------------------------------------------
    // 4. VARIABLES AND DATA TYPES
    // --------------------------------------------------------
    cout << "=== 1. Variables & Data Types ===" << endl;
    int age = 18;
    double gpa = 1.75;
    float temperature = 36.5f;
    char letter = 'A';
    bool isStudent = true;
    string name = "Paul";

    cout << "Name: " << name << ", Age: " << age << ", GPA: " << gpa << endl;
    cout << "Temp: " << temperature << ", Letter: " << letter
         << ", Student? " << boolalpha << isStudent << endl;
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;

    auto inferred = 42;   // auto: compiler deduces the type (int)
    cout << "Auto-deduced value: " << inferred << endl;

    // --------------------------------------------------------
    // 5. OPERATORS
    // --------------------------------------------------------
    cout << "\n=== 2. Operators ===" << endl;
    int a = 10, b = 3;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << " (integer division)" << endl;
    cout << "a % b = " << a % b << " (remainder)" << endl;
    cout << "a > b && b > 0 -> " << (a > b && b > 0) << endl;
    cout << "a == b || a != b -> " << (a == b || a != b) << endl;
    a++;   // increment
    b -= 1; // compound assignment
    cout << "After a++ and b -= 1: a = " << a << ", b = " << b << endl;

    // --------------------------------------------------------
    // 6. USER INPUT
    // --------------------------------------------------------
    cout << "\n=== 3. User Input ===" << endl;
    int score;
    cout << "Enter your score (0-100): ";
    cin >> score;

    // --------------------------------------------------------
    // 7. CONDITIONALS
    // --------------------------------------------------------
    cout << "\n=== 4. Conditionals ===" << endl;
    if (score >= 90) {
        cout << "Excellent!" << endl;
    } else if (score >= 75) {
        cout << "Passed." << endl;
    } else {
        cout << "Needs improvement." << endl;
    }

    Grade g = (score >= 75) ? PASS : FAIL;        // ternary operator
    cout << "Grade enum value: " << g << endl;

    int day = 3;
    switch (day) {                                // switch statement
        case 1: cout << "Monday" << endl; break;
        case 2: cout << "Tuesday" << endl; break;
        case 3: cout << "Wednesday" << endl; break;
        default: cout << "Other day" << endl;
    }

    // --------------------------------------------------------
    // 8. LOOPS
    // --------------------------------------------------------
    cout << "\n=== 5. Loops ===" << endl;

    cout << "for loop:    ";
    for (int i = 1; i <= 5; i++) cout << i << " ";
    cout << endl;

    cout << "while loop:  ";
    int w = 5;
    while (w > 0) { cout << w << " "; w--; }
    cout << endl;

    cout << "do-while:    ";
    int d = 0;
    do { cout << d << " "; d++; } while (d < 3);
    cout << endl;

    cout << "break/continue (skip 3, stop at 6): ";
    for (int i = 1; i <= 10; i++) {
        if (i == 3) continue;
        if (i == 6) break;
        cout << i << " ";
    }
    cout << endl;

    // --------------------------------------------------------
    // 9. ARRAYS, VECTORS, AND STRINGS
    // --------------------------------------------------------
    cout << "\n=== 6. Arrays, Vectors & Strings ===" << endl;

    int numbers[5] = {5, 2, 9, 1, 7};             // fixed-size array
    cout << "Array: ";
    for (int i = 0; i < 5; i++) cout << numbers[i] << " ";
    cout << endl;

    vector<int> vec = {5, 2, 9, 1, 7};            // dynamic array
    vec.push_back(4);
    sort(vec.begin(), vec.end());
    cout << "Sorted vector: ";
    for (int n : vec) cout << n << " ";           // range-based for loop
    cout << "(size: " << vec.size() << ")" << endl;

    string greeting = "Hello";
    greeting += ", World!";
    cout << greeting << " (length: " << greeting.length() << ")" << endl;
    cout << "First char: " << greeting[0]
         << ", Substring: " << greeting.substr(0, 5) << endl;

    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};    // 2D array
    cout << "2D array element [1][2]: " << matrix[1][2] << endl;

    // --------------------------------------------------------
    // 10. FUNCTIONS IN ACTION
    // --------------------------------------------------------
    cout << "\n=== 7. Functions ===" << endl;
    cout << "add(2, 3) = " << add(2, 3) << endl;
    cout << "add(2.5, 3.5) = " << add(2.5, 3.5) << endl;
    cout << "power(5) = " << power(5) << " (default exp = 2)" << endl;
    cout << "power(2, 10) = " << power(2, 10) << endl;
    cout << "factorial(5) = " << factorial(5) << endl;
    cout << "maxOf(3, 8) = " << maxOf(3, 8)
         << ", maxOf(2.5, 1.5) = " << maxOf(2.5, 1.5) << endl;

    int x = 1, y = 2;
    swapByRef(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;

    // --------------------------------------------------------
    // 11. POINTERS AND REFERENCES
    // --------------------------------------------------------
    cout << "\n=== 8. Pointers & References ===" << endl;
    int value = 100;
    int *ptr = &value;        // pointer stores the address of value
    int &ref = value;         // reference is an alias for value

    cout << "value = " << value << ", *ptr = " << *ptr << ", ref = " << ref << endl;
    *ptr = 200;               // changing through the pointer
    cout << "After *ptr = 200 -> value = " << value << endl;

    int *dyn = new int(42);   // dynamic memory
    cout << "Dynamic int: " << *dyn << endl;
    delete dyn;               // always free what you new

    auto smart = make_unique<int>(99);  // smart pointer (auto cleanup)
    cout << "Smart pointer value: " << *smart << endl;

    // --------------------------------------------------------
    // 12. STRUCTS AND ENUMS
    // --------------------------------------------------------
    cout << "\n=== 9. Structs & Enums ===" << endl;
    Point p = {3, 4};
    cout << "Point: (" << p.x << ", " << p.y << ")" << endl;

    Grade result = HONORS;
    if (result == HONORS) cout << "Graduated with honors!" << endl;

    // --------------------------------------------------------
    // 13. CLASSES AND OOP
    // --------------------------------------------------------
    cout << "\n=== 10. Classes & OOP ===" << endl;
    vector<Shape*> shapes;                        // polymorphism
    shapes.push_back(new Circle(5));
    shapes.push_back(new Rectangle(4, 6));

    for (Shape *s : shapes) {
        s->describe();                            // calls the right version
    }
    for (Shape *s : shapes) delete s;

    BankAccount account(1000);
    account.deposit(500);
    cout << "Account balance: " << account.getBalance() << endl;

    // --------------------------------------------------------
    // 14. EXCEPTION HANDLING
    // --------------------------------------------------------
    cout << "\n=== 11. Exception Handling ===" << endl;
    try {
        account.withdraw(5000);                   // too much!
        cout << "This line will not run." << endl;
    } catch (const runtime_error &e) {
        cout << "Caught error: " << e.what() << endl;
    }

    // --------------------------------------------------------
    // 15. STL MAP AND LAMBDA
    // --------------------------------------------------------
    cout << "\n=== 12. Map & Lambda ===" << endl;
    map<string, int> grades;
    grades["Math"] = 90;
    grades["Programming"] = 95;
    grades["English"] = 85;

    for (const auto &pair : grades) {
        cout << pair.first << ": " << pair.second << endl;
    }

    auto square = [](int n) { return n * n; };    // lambda function
    cout << "square(7) = " << square(7) << endl;

    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int evens = count_if(nums.begin(), nums.end(),
                         [](int n) { return n % 2 == 0; });
    cout << "Even numbers in list: " << evens << endl;

    cout << "\n=== End of showcase ===" << endl;
    return 0;
}