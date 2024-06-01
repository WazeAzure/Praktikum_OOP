#include "Rekening.h"

Rekening::Rekening(double saldo){
    this->saldo = saldo;
    if(saldo < 0){
        this->saldo = 0;
    }
}

void Rekening::setSaldo(double saldo){
    this->saldo = saldo;
}

double Rekening::getSaldo() const {
    return this->saldo;
}

void Rekening::simpanUang(double pemasukan){
    this->saldo += pemasukan;
}

bool Rekening::tarikUang(double pengeluaran){
    if(this->saldo >= pengeluaran){
        this->saldo -= pengeluaran;
        return true;
    }
    return false;
}