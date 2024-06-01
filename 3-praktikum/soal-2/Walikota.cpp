#include "Walikota.hpp"
#include <iostream>
using namespace std;

Walikota::Walikota(){
    this->kayu = DEFAULT_KAYU;
    this->gulden = DEFAULT_GULDEN;
    this->pekerja = DEFAULT_PEKERJA;
}

Walikota::Walikota(int kayu, int gulden, int pekerja){
    this->kayu = kayu;
    this->gulden = gulden;
    this->pekerja = pekerja;
}

Walikota::~Walikota(){}

void Walikota::bangunBangunan(string namaBangunan, int kayu, int gulden){
    try {
        pakaiKayu(kayu);
        pakaiGulden(gulden);
        pekerjakanPekerja();
        Bangunan a(namaBangunan);

        this->bangunan.push_back(a);

        cout << "Bangunan [" << this->bangunan.size() << "] " << namaBangunan << " berhasil dibangun" << endl;
    } catch(KayuTidakCukupException e){
        cout << e.what() << ", beli kayu dulu.\n";
    } catch(GuldenTidakCukupException e){
        cout << e.what() << ", tagih pajak dulu.\n";
        batalPakaiKayu(kayu);
    } catch(PekerjaTidakCukupException e){
        batalPakaiKayu(kayu);
        batalPakaiGulden(gulden);
        cout << e.what() << ", rekrut pekerja dulu.\n";
    }
}

void Walikota::tambahKayu(int num){
    this->kayu += num;
}

void Walikota::tambahGulden(int num){
    this->gulden += num;
}

void Walikota::tambahPekerja(int num){
    this->pekerja += num;
}

void Walikota::pakaiKayu(int num){
    if(num > this->kayu){
        KayuTidakCukupException k;
        throw k;
    }
    this->kayu -= num;
}

void Walikota::pakaiGulden(int num){
    if(num > this->gulden){
        GuldenTidakCukupException k;
        throw k;
    }
    this->gulden -= num;
}

void Walikota::pekerjakanPekerja(){
    if(this->pekerja <= 0){
        PekerjaTidakCukupException k;
        throw k;
    }
    this->pekerja--;
}

void Walikota::batalPakaiKayu(int num){
    this->kayu += num;
}

void Walikota::batalPakaiGulden(int num){
    this->gulden += num;
}

void Walikota::batalkanPekerja(){
    this->pekerja++;
}

void Walikota::sebutBangunan(int idx){
    try {
        cout << this->bangunan.at(idx).getNamaBangunan() << endl;
    } catch(exception &e){
        cout << e.what() << endl;
    }
}

void Walikota::statusKota(){
    cout << "Status" << endl
         << "  Kayu: " << this->kayu << endl
         << "  Gulden: " << this->gulden << endl
         << "  Pekerja: " << this->pekerja << endl
         << "  Bangunan:" << endl;
    for(int i=0; i<this->bangunan.size(); i++){
        cout << "    Bangunan[" << i+1 << "]: " << this->bangunan[i].getNamaBangunan() << endl; 
    }
}