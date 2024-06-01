#include <iostream>
#include "memo.h"
#include "exception.h"

/* 
    Membuat objek Memo dengan 'pesan' dan 'untuk' kosong
*/
Memo::Memo() {
    this->pesan = "";
    this->untuk = "";
}
/* 
    Membuat objek Memo dengan isi sesuai yang diberikan.
    
    Jika panjang pesan melebihi panjang maksimum, maka
    metode ini melemparkan PesanKepanjanganException.
*/
Memo::Memo(string pesan, string untuk) {
    if (pesan.length() > PESAN_MAX) {
        PesanKepanjanganException e;
        throw e;
    } else {
        this->pesan = pesan;
        this->untuk = untuk;
    }
}
/* 
    Menyalin nilai pesan dan untuk ke objek lain
*/
Memo& Memo::operator=(Memo& obj) {
    this->pesan = obj.pesan;
    this->untuk = obj.untuk;
}
/*
    Mendapatkan nilai pesan
*/
string Memo::getPesan() {
    return this->pesan;
}
/*
    Mendapatkan nilai untuk
*/
string Memo::getUntuk() {
    return this->untuk;
}