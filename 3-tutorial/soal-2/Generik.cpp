#include <iostream>
using namespace std;

template<class P>
void func(P param1, P param2) {
    cout << "Masukan Anda: " << param1 << " dan " << param2 << ", memiliki tipe yang sama" << endl;
}

template<class P, class Q>
void func(P param1, Q param2) {
    cout << "Masukan Anda: " << param1 << " dan " << param2 << ", mungkin memiliki tipe yang berbeda" << endl;
}

template<>
void func<char, int>(char param1, int param2) {
    for (int i = 0; i < param2; i++) {
        cout << param1 << endl;
    }
}