#include "generic-vector.hpp"
#include <iostream>

using namespace std;

int main(){
    Vector<int, 3> a;
    cin >> a;
    cout << a << endl;

    Vector<int, 3> b;
    cin >> b;

    Vector<int, 3> d = b;
    b = a;

    try {
        b[100] = 100;
    } catch(myOwnError err){
        cout << err.what() << endl;
    }

    Vector<int, 3> c = a + b;
    cout << c << endl;


}