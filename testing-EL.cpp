#include "testing-EL.hpp"
#include <iostream>

int main(){
    A* ptr;
    B b(2, 3);

    ptr = &b;

    std::cout << ptr->getI() << std::endl;

    return 0;
}