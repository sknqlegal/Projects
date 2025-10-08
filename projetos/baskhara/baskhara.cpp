#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

class Bhaskhara{
    public:
        int start(){
            std::string choice;
            std::cout << "Start application? [y/n]:" << std::endl;
            std::cin >> choice;

             if (choice == "y"){
                return 1;
            }
        }

        int calc(){
            double a, b, c;
            
            std::cout << "Enter the coeficients of your function." << std::endl;
            std::cin >> a >> b >> c;
        
            int delta = b*b - 4*a*c;
            if (delta < 0){
                delta *= -1; //multiplying it by -1 if negative prevents nan root value (line below)
            }
            double deltaRoot = trunc(sqrt(delta)); //truncating cuz apparently some values for delta makes it so an irrational deltaRoot^2 == delta
            
            if (b*b - 4*a*c < 0){
                std::cout << "Your function has no real values. Show complex solutions? [y/n]: ";
                std::string choice;
                std::cin >> choice;

                if (choice == "y"){
                    if (pow(deltaRoot, 2) == delta){ //if its a perfect root
                        
                        std::cout << "(" << -b << " + " << std::setprecision(2) << deltaRoot << "i" << ")" << " / " << (2 * a) << std::endl
                                  << "(" << -b << " - " << std::setprecision(2) << deltaRoot << "i" << ")" << " / " << (2 * a) << std::endl;
                    }
                    else if (pow(deltaRoot, 2) != delta){

                        std::cout << "(" << -b << " + " << "sqrt(" << delta << ")i )" << " / " << (2 * a) << std::endl
                                  << "(" << -b << " - " << "sqrt(" << delta << ")i )" << " / " << (2 * a) << std::endl;

                            std::string choice;
                            std::cout << "Approximate results? [y/n]:" << std::endl;
                            std::cin >> choice;
                            if (choice == "y"){
                              std::cout << std::setprecision(2) << (-b + deltaRoot) / (2 * a) << std::endl
                                        << std::setprecision(2) << (-b - deltaRoot) / (2 * a) << std::endl;
                            }
                    }
                }
            }

            else if (b*b - 4*a*c == 0){
                std::cout << -b / (2 * a) << std::endl;
            }

            else if (b*b - 4*a*c > 0){
                if (pow(deltaRoot, 2) == delta){
                        
                        std::cout << (-b + deltaRoot) / (2 * a) << std::endl << (-b - deltaRoot) / (2 * a) << std::endl;
                    }
                if (pow(deltaRoot, 2) != delta){
                        
                        std::cout << "(" << -b << " + " << "sqrt(" << delta << "))" << " / " << (2 * a) << std::endl
                                  << "(" << -b << " - " << "sqrt(" << delta << "))" << " / " << (2 * a) << std::endl;

                            std::string choice;
                            std::cout << "Approximate results? [y/n]:" << std::endl;
                            std::cin >> choice;
                            if (choice == "y"){
                              std::cout << std::setprecision(2) << (-b + deltaRoot) / (2 * a) << std::endl
                                        << std::setprecision(2) << (-b - deltaRoot) / (2 * a) << std::endl;
                            }
                    }
            }
            return 1;
        }
    };

    int main(){
        Bhaskhara().start();
        while(Bhaskhara().calc()){}
        return 0;
    }