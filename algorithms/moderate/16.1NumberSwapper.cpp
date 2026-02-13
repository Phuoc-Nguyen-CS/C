// Write a function to swap a number in place

#include <iostream>

int main() {
    int a = 4;
    int b = 7;
    
    std::cout << "Before: "<< a << " " << b << std::endl;
    
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    std::cout << "After:  " << a << " " << b<< std::endl;
    return 0;
}