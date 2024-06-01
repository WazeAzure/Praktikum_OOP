#include "KoleksiKendaraan.hpp"

KoleksiKendaraan::KoleksiKendaraan(){
    this->size = 100;
    this->neff = 0;
    this->arr = new Kendaraan*[this->size];
}

KoleksiKendaraan::KoleksiKendaraan(int size){
    this->size = size;
    this->neff = 0;
    this->arr = new Kendaraan*[this->size];
}

KoleksiKendaraan::KoleksiKendaraan(const KoleksiKendaraan& k){
    this->size = k.size;
    this->neff = k.neff;
    this->arr = new Kendaraan*[this->size];

    int i;
    for(i=0; i<k.neff; i++){
        this->arr[i] = k.arr[i];
    }
}

KoleksiKendaraan::~KoleksiKendaraan(){
    cout << "=== KoleksiKendaraan DESTRUCTOR CALLED ===" << endl;
    delete [] this->arr;
}

KoleksiKendaraan& KoleksiKendaraan::operator=(const KoleksiKendaraan& k){
    this->size = k.size;
    this->neff = k.neff;
    this->arr = new Kendaraan*[this->size];

    int i;
    for(i=0; i<k.neff; i++){
        this->arr[i] = k.arr[i];
    }
    return *this;
}

void KoleksiKendaraan::printAll() const {
    int i;
    for(i=0; i<this->neff; i++){
        this->arr[i]->printinfo();
    }
}

void KoleksiKendaraan::operator<<(Kendaraan& k){
    // **
    this->arr[this->neff] = &k;
    this->neff++;
}

void KoleksiKendaraan::operator<<(const KoleksiKendaraan& k){
    int count = 0;
    while(this->neff != this->size && count < k.neff){
        this->arr[this->neff] = k.arr[count];
        count++;
        this->neff++;
    }
}