#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

int calcs() {
    std::string operation;
    std::cout << "select operation (lowercase)" << std::endl << "([A]ddition, [S]ubtraction, [D]ivision, [M]ultiplication, [P]ower, [SQRT] square root, [E]xit)" << std::endl;
    std::cin >> operation;
    
    int num1{ 0 }, num2{ 0 };
    if (operation == "a") {
        std::cout << "type in 2 numbers: ";
        std::cin >> num1 >> num2;
        int result = num1 + num2;
        std::cout << std::endl << "result: " << result << std::endl << std::endl;
    }
    else if (operation == "s") {
        std::cout << "type in 2 numbers: ";
        std::cin >> num1 >> num2;
        int result = num1 - num2;
        std::cout << std::endl << "result: " << result << std::endl << std::endl;
    }
    else if (operation == "d") {
        std::cout << "type in 2 numbers: ";
        std::cin >> num1 >> num2;
        double result = (double)num1 / num2;
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
    }
    else if (operation == "m") {
        std::cout << "type in 2 numbers: ";
        std::cin >> num1 >> num2;
        int result = num1 * num2;
        std::cout << std::endl << "result: " << result << std::endl << std::endl;
    }
    else if (operation == "p") {
        std::cout << "type in 2 numbers (1st is base, 2nd is power): ";
        std::cin >> num1 >> num2;
        double result = pow(num1, num2);
        std::cout << std::endl << "result: " << result << std::endl << std::endl;
    }
    else if (operation == "sqrt") {
        std::cout << "type in the number: ";
        std::cin >> num1;
        double result = sqrt(num1);
        if (num1 == pow(result, 2)) {
            std::cout << std::endl << "result: " << result << std::endl << std::endl;
        }
        else{
            std::cout << std::endl << "result (approximate): " << std::setprecision(2) << result << std::endl << std::endl;
        }
    }
    else if (operation == "e") {
        return 0;
    }
    else{
        std::cerr << "unknown command" << std::endl << std::endl;
        return 1;
    }
}

int main() {
    while (calcs()) {} //makes it so the program loops until user iputs 'e'
    return 0;
}