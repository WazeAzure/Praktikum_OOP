#include "Weed.hpp"

#include <iostream>
using namespace std;

Weed::Weed(){
    many = 1;
}

Weed::Weed(int n){
    many = n;
}

Weed::Weed(const Weed &b){

    many = b.many;
}

Weed::~Weed(){

}

void Weed::step(){
    int i=0;
    for(i=0; i<this->many; i++){
        cout << "kresek...";
    }
    cout << endl;
}