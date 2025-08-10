#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

int calcs() {
    char operation;
    std::cout << "select operation" << std::endl << "([a]ddition, [s]ubtraction, [d]ivision, [m]ultiplication, [p]ower, [S]quare root, [e]xit)" << std::endl;
    std::cin >> operation;
    
    double num1{ 0 }, num2{ 0 };
    double result;
    switch(operation){
        case 'a':
            std::cout << "type in 2 numbers: ";
            std::cin >> num1 >> num2;
            result = num1 + num2;
            std::cout << std::endl << "result: " << result << std::endl << std::endl;
            break;

        case 's':
            std::cout << "type in 2 numbers: ";
            std::cin >> num1 >> num2;
            result = num1 - num2;
            std::cout << std::endl << "result: " << result << std::endl << std::endl;
            break;
        
        case 'd':
            std::cout << "type in 2 numbers: ";
            std::cin >> num1 >> num2;
            result = (double)num1 / num2;
            if (num2 == 0) {
                std::cout << "can't divide by zero";
            }
            else {
                if (result * 100 == round(result * 100)){
                    std::cout << std::endl << "result: " << result << std::endl << std::endl;
                }
                else{
                    std::cout << std::endl << "result (approximate): " << std::setprecision(2) << result << std::endl << std::endl;
                }
            }
            break;

        case 'm':
            std::cout << "type in 2 numbers: ";
            std::cin >> num1 >> num2;
            result = num1 * num2;
            std::cout << std::endl << "result: " << result << std::endl << std::endl;
            break;

        case 'p':
            std::cout << "type in 2 numbers (1st is base, 2nd is power): ";
            std::cin >> num1 >> num2;
            result = pow(num1, num2);
            std::cout << std::endl << "result: " << result << std::endl << std::endl;
            break;

        case 'S': 
            std::cout << "type in the number: ";
            std::cin >> num1;
            result = sqrt(num1);
            if (num1 == pow(result, 2)) {
                std::cout << std::endl << "result: " << result << std::endl << std::endl;
            }
            else{
                std::cout << std::endl << "result (approximate): " << std::setprecision(2) << result << std::endl << std::endl;
            }
            break;

        case 'e':
            return 0;
            break;

        default:
            std::cerr << "unknown command" << std::endl << std::endl;
            break;
        }
        return 1;
}

int main() {
    while (calcs()) {} //makes it so the program loops until user iputs 'e'
    return 0;
}