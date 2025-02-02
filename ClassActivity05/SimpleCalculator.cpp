#include <iostream>

using namespace std;


int main() {
    double num1;
    cout << "Pick a number:" << endl;
    cin >> num1;
    
    char operation;
    cout << "Pick an operation: (+, -, *, /)" << endl;
    cin >> operation;
    
    double num2;
    cout << "Pick another number:" << endl;
    cin >> num2;
    
    switch(operation){      // switch will test value against each case and perform action if true
        case '+':
            cout << num1 << operation << num2 << "=" << num1 + num2 << endl;
            break;      // compiler will stop reading code as soon as answer is found, rather than going through rest of code
        case '-':
            cout << num1 << operation << num2 << "=" << num1 - num2 << endl;
            break;
        case '*':
            cout << num1 << operation << num2 << "=" << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0){
                cout << num1 << operation << num2 << "=" << num1 / num2 << endl;
                break;
            }
            cout << "Error, Cannot divide by 0" << endl;
            break;
        default:
            cout << "Invalid input for operation" << endl;
    }
    
    
    return 0;
}
