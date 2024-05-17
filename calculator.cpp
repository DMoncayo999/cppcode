#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// class definitioon for calculator
class Calculator {
public:
    // functions to add two numbers
    double Add(double a, double b) {
        return a + b;
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
    Calculator calc;
    char operation;
    double num1, num2, result;
    vector<double> history;

    while (true) {
        cout << "Enter operation (+, -, *, /) or q to quit: ";
        cin >> operation;

        if (operation == 'q') {
            break;
        }

        cout << "Enter first number: " << endl;
        cin >> num1;

        cout << "Enter second number: " << endl;
        cin >> num2;

        try {
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
            cout << "Result: " << result << endl;
            history.push_back(result);
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    cout << "Calculation history:" << endl;
    for (double value : history) {
        cout << value << endl;
    }

    return 0;
}