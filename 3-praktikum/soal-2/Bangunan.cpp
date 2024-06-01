#include "Bangunan.hpp"

Bangunan::Bangunan(){
    this->namaBangunan = "Bangunan Kosong";
}

Bangunan::Bangunan(string namaBangunan){
    this->namaBangunan = namaBangunan;
}

string Bangunan::getNamaBangunan(){
    return this->namaBangunan;
}