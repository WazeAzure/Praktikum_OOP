#include "RekeningTabungan.h"

RekeningTabungan::RekeningTabungan(double saldo, double biayaTransaksi) : Rekening(saldo) {
    this->biayaTransaksi = biayaTransaksi;
    if(biayaTransaksi < 0){
        this->biayaTransaksi = 0;
    }
}

void RekeningTabungan::setBiayaTransaksi(double biayaTransaksi){
    this->biayaTransaksi = biayaTransaksi;
}

double RekeningTabungan::getBiayaTransaksi() const {
    return this->biayaTransaksi;
}

void RekeningTabungan::simpanUang(double saldo){
    saldo -= this->biayaTransaksi;
    Rekening::simpanUang(saldo);
}

bool RekeningTabungan::tarikUang(double pengeluaran){
    if(Rekening::tarikUang(pengeluaran)){
        Rekening::setSaldo(Rekening::getSaldo() - this->biayaTransaksi);
        return true;
    }
    return false;
}