#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;
    char choice;


    do {
        cout << "\nEnter the first number: ";
        cin >> num1;

        cout << "Enter an operator (+, -, *, /): ";
        cin >> operation;

        cout << "Enter the second number: ";
        cin >> num2;

        cout << "\nCalculating...\n";

        switch(operation) {
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
                if (num2 != 0)
                    cout << "Result: " << num1 << " / " << num2 << " = " << num1 / num2 << endl;
                else
                    cout << "Error: Division by zero is not allowed.\n";
                break;

            default:
                cout << "Invalid operator. Please try again.\n";
        }

       
    } while(choice == 'y' || choice == 'Y');

    cout << "\nThank you for using the calculator. Goodbye.\n";

    return 0;
}