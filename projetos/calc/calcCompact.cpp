#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std; // -> = igual; ~> = aprox

class Calculator{
    public:
        Calculator(){
            cout << "Select operation" << endl <<
            "    [a]ddition" << endl <<
            "    [s]ubtraction" << endl <<
            "    [d]ivision" << endl <<
            "    [m]ultiplication" << endl <<
            "    [p]ower" << endl <<
            "    [S]quare root" << endl <<
            "    [e]xit" << endl << endl;
        }

    int calcs(void){
        char operation;
        cin >> operation;
    
        //for special cases
        if (operation == 'e'){
            return 0;
        }
        else if (string("asdmpS").find(operation) == string::npos){ //if letter chosen is not an operation
            std::cerr << "unknown command!" << endl;
            return 1;
        }
        else if(operation == 'S'){
            cout << "type in the number: ";
            double num1{ 0 };
            cin >> num1;
            cout << endl;
            
            if (num1 == pow(sqrt(num1), 2)) {
                    cout << "-> " <<  sqrt(num1) << endl << endl;
                }
                else{
                    cout << "~> " << setprecision(2) << sqrt(num1) << endl << endl;
                }
                return 1;
        }
    
        //normal operations
        cout << "type in 2 numbers: ";
        double num1{ 0 }, num2{ 0 };
        cin >> num1 >> num2;
        cout << endl;
        
        switch(operation){
            case 'a':
                cout << "-> " << num1 + num2 << endl << endl;
                break;
    
            case 's':
                cout << "-> " << num1 - num2 << endl << endl;
                break;
    
            case 'd':
                double result;
                result = num1 / num2;
                if (num2 == 0) {
                    cout << "can't divide by zero" << endl << endl;
                }
                else {
                    if (result * 10000 == round(result * 10000)){
                        cout << "-> " << result << endl << endl;
                    }
                    else{
                        cout << "~> " << setprecision(3) << result << endl << endl;
                    }
                }
                break;
    
            case 'm':
                cout << "-> " << num1 * num2 << endl << endl;
                break;
    
            case 'p':
                cout << "-> " << pow(num1, num2) << endl << endl;
                break;
            }
            return 1;
    }
};

int main(){
    while(Calculator().calcs()) {}
    return 0;
}