#include <iostream>
#include <iomanip> // for controlling decimal precision
using namespace std;

int main() {
    cout << "======================================================" << endl;
    cout << "           Welcome to the  Calculator!           " << endl;
    cout << "======================================================" << endl;

    char continueCalc;

    cout << "Press 'c' to calculate or any other key to exit: ";
    cin >> continueCalc;

    while (continueCalc == 'c' || continueCalc == 'C') {
        float num1, num2;
        char op;

        // Taking input from the user
        cout << "\nEnter the first number: ";
        cin >> num1;

        cout << "Enter the second number: ";
        cin >> num2;

        cout << "Enter operator (+, -, *, /): ";
        cin >> op;

        // Set precision for float output
        cout << fixed << setprecision(2);

        // Perform calculation based on operator
        switch(op) {
            case '+':
                cout << "Result: " << num1 << " + " << num2 << " = " << num1 + num2 << endl;
                break;
            case '-':
                cout << "Result: " << num1 << " - " << num2 << " = " << num1 - num2 << endl;
                break;
            case '*':
                cout << "Result: " << num1 << " * " << num2 << " = " << num1 * num2 << endl;
                break;
            case '/':
                if (num2 != 0) {
                    cout << "Result: " << num1 << " / " << num2 << " = " << num1 / num2 << endl;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                }
                break;
            default:
                cout << "Invalid operator! Please use one of +, -, *, /" << endl;
        }

        // Ask to continue
        cout << "\nWould you like to try again? (Press 'c' to continue, anything else to exit): ";
        cin >> continueCalc;
        cout << "------------------------------------------------------" << endl;
    }

    cout << "\nThank you for using this calculator!  See you again!" << endl;
    return 0;
}
