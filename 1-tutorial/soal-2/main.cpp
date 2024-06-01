#include "A.hpp"
#include <iostream>

void temp(A& a1){
    A x('3');
    a1 = x;
}

int main(){
    A x('1');
    A y('2');
    A ab;
    A z = x;
    z = y;
    y.show();

    temp(ab);

    ab.show();

    return 0;
}
