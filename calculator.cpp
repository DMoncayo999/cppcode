#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// CLASS definition for calculator
class Calculator {
public:

    // FUNCTIONS
    // Function to add two numbers
    double Add(double a, double b) {
        return a + b; // Arithmethic EXPRESSION
    }
    // Function to substract two numbers
    double Subtract(double a, double b) {
        return a - b;  
    }
    // Function to multiply two numbers
    double Multiply(double a, double b) {
        return a * b;
    }
    // Function to divide two numbers
    double Divide(double a, double b) {
        if (b == 0) {
            throw invalid_argument("Division by zero");
        }
        return a / b;
    }
};

int main() {
    Calculator calc;  // Create a instance of the calculator
    char operation;   // VARIABLE to store user's choice of arithmetic operation
    double num1, num2, result;  // VARIABLE to store the user input for first and second number
    
    vector<double> history; // VECTOR to store calculation

    // LOOP
    while (true) {
        // Prompt the user to enter an operation or 'q' to quit
        cout << "Enter operation (+, -, *, /) or q to quit: ";
        cin >> operation;

        // Check if user wants to quit
        if (operation == 'q') {
            break;
        }

        // Prompt the user to enter first number
        cout << "Enter first number: " << endl;
        cin >> num1;

        // Prompt the user to enter second number
        cout << "Enter second number: " << endl;
        cin >> num2;

        // CONDITIONAL
        try {
            // Perform the appropiate operation based on user input
            switch (operation) {
                case '+':
                    result = calc.Add(num1, num2);
                    break;
                case '-':
                    result = calc.Subtract(num1, num2);
                    break;
                case '*':
                    result = calc.Multiply(num1, num2);
                    break;
                case '/':
                    result = calc.Divide(num1, num2);
                    break;
                default:
                    throw invalid_argument("Invalid operation");
            }

            // Display the result of the calculation
            cout << "Result: " << result << endl;

            // Store the result in the history VECTOR
            history.push_back(result);

        } catch (const exception& e) {
            // Handle exceptions (eg. division by zero)
            cerr << "Error: " << e.what() << endl;
        }
    }

    // Displaya athe calculation history
    cout << "Calculation history:" << endl;
    for (double value : history) {
        cout << value << endl;
    }

    return 0; // Exit the program
}