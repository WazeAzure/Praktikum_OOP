#include "RekeningGiro.h"

RekeningGiro::RekeningGiro(double saldo, double sukuBunga) : Rekening(saldo) {
    this->sukuBunga = sukuBunga;
    if(sukuBunga < 0){
        this->sukuBunga = 0;
    }
}

void RekeningGiro::setSukuBunga(double sukuBunga){
    this->sukuBunga = sukuBunga;
}

double RekeningGiro::getSukuBunga() const {
    return this->sukuBunga;
}

double RekeningGiro::hitungBunga(){
    return this->sukuBunga * this->getSaldo();
}
