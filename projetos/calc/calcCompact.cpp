#include <iostream>
#include <cmath>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;

int calcs() {
    cout << "select operation" << endl << "([a]ddition, [s]ubtraction, [d]ivision, [m]ultiplication, [p]ower, [S]quare root, [e]xit)" << endl;
    char operation;
    cin >> operation;
    
    cout << "type in 2 numbers (1 if sqrt): ";
    double num1{ 0 }, num2{ 0 };
    cin >> num1 >> num2;
    cout << endl;
    switch(operation){
        case 'a':
            cout << num1 + num2 << endl << endl;
            break;

        case 's':
            cout << num1 - num2 << endl << endl;
            break;

        case 'd':
            double result = num1 / num2;
            if (num2 == 0) {
                cout << "can't divide by zero";
            }
            else {
                if (result * 100 == round(result * 100)){
                    cout << result << endl << endl;
                }
                else{
                    cout << "approximate: " << std::setprecision(3) << result << endl << endl;
                }
            }
            break;

        case 'm':
            cout << num1 * num2 << endl << endl;
            break;

        case 'p':
            cout << pow(num1, num2) << endl << endl;
            break;

        case 'S': 

            if (num1 == pow(sqrt(num1), 2)) {
                cout << sqrt(num1) << endl << endl;
            }
            else{
                cout << "approximate: " << std::setprecision(2) << sqrt(num1) << endl << endl;
            }
            break;

        case 'e':
            return 0;
            break;

        default:
            std::cerr << "unknown command" << endl << endl;
            break;
        }
        return 1;
}

int main() {
    while (calcs()) {} //makes it so the program loops until user iputs 'e'
    return 0;
}