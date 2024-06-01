#include "Kendaraan.hpp"

int Kendaraan::no_kendaraan = 0;

Kendaraan::Kendaraan(): id(no_kendaraan) {
    cout << "=== CALLED DEFAULT CONSTRUCTOR ===" << endl;
    this->kategori = "Mobil";
    this->merk = "XXX";
    this->tahun_keluaran = 0;
    Kendaraan::no_kendaraan++;
}

Kendaraan::Kendaraan(string merk, string kategori, int tahun_keluaran): id(no_kendaraan) {
    this->kategori = kategori;
    this->merk = merk;
    this->tahun_keluaran = tahun_keluaran;
    Kendaraan::no_kendaraan++;
}

Kendaraan::Kendaraan(const Kendaraan& k): id(no_kendaraan) {
    cout << "=== CALLED COPY CONSTRUCTOR ===" << endl;
    this->kategori = k.kategori;
    this->merk = k.merk;
    this->tahun_keluaran = k.tahun_keluaran;
    Kendaraan::no_kendaraan++;
}

Kendaraan::~Kendaraan(){
    cout << "=== Kendaraan DESTRUCTOR CALLED ===" << endl;
}

Kendaraan& Kendaraan::operator=(const Kendaraan& k) {
    cout << "=== CALLED ASSIGNMENT KENDARAAN ===" << endl;
    this->kategori = k.kategori;
    this->merk = k.merk;
    this->tahun_keluaran = k.tahun_keluaran;
    Kendaraan::no_kendaraan++;
    return *this;
}

void Kendaraan::printinfo() const {
    cout << this->id << endl
        << this->kategori << endl
        << this->merk << endl
        << this->tahun_keluaran << endl;
}

int Kendaraan::biayaSewa(int lamaSewa){
    if(this->kategori == "Bus"){
        return 1000000 * lamaSewa;
    } else if(this->kategori == "MiniBus"){
        if (lamaSewa <= 5){
            return 5000000;
        } else {
            return 5000000 + 500000 * (lamaSewa - 5);
        }
    } else {
        return 500000 * lamaSewa;
    }
}

Bus::Bus(): Kendaraan(){
    this->kapasitas = 0;
    this->kategori = "Bus";
}

Bus::Bus(string merk, string kategori, int tahun_keluaran, int kapasitas): Kendaraan(merk, kategori, tahun_keluaran) {
    this->kapasitas = kapasitas;
    this->kategori = "Bus";
}

Bus::Bus(const Bus& b): Kendaraan(b){
    this->kapasitas = b.kapasitas;
}

Bus::~Bus(){
    cout << "=== Bus DESTRUCTOR CALLED ===" << endl;
}

Bus& Bus::operator=(const Bus& b){
    cout << "=== CALLED ASSIGNMENT BUS ===" << endl;
    this->kategori = b.kategori;
    this->merk = b.merk;
    this->tahun_keluaran = b.tahun_keluaran;
    this->kapasitas = b.kapasitas;
    Kendaraan::no_kendaraan++; 
    return *this;
}

void Bus::printinfo() const {
    Kendaraan::printinfo();
    cout << "kapasitas: " << this->kapasitas << endl;
}

int Bus::biayaSewa(int lamaSewa) {
    return Kendaraan::biayaSewa(lamaSewa);
}

// -- mobil

Mobil::Mobil(): Kendaraan(){
    this->kategori = "Mobil";
    this->supir = "XXXX";
}

Mobil::Mobil(string merk, string kategori, int tahun_keluaran, string supir): Kendaraan(merk, kategori, tahun_keluaran) {
    this->kategori = "Mobil";
    this->supir = supir;
}

Mobil::Mobil(const Mobil& b): Kendaraan(b){
    this->supir = b.supir;
}

Mobil::~Mobil(){
    cout << "=== Mobil DESTRUCTOR CALLED ===" << endl;
}

Mobil& Mobil::operator=(const Mobil& b){
    this->kategori = b.kategori;
    this->merk = b.merk;
    this->tahun_keluaran = b.tahun_keluaran;
    this->supir = b.supir;
    Kendaraan::no_kendaraan++; 
    return *this;
}

void Mobil::printinfo() const {
    Kendaraan::printinfo();
    cout << "supir: " << this->supir << endl;
}

int Mobil::biayaSewa(int lamaSewa) {
    return Kendaraan::biayaSewa(lamaSewa);
}

// -- minibus

Minibus::Minibus(): Kendaraan(){
    this->kategori = "Minibus";
}

Minibus::Minibus(string merk, string kategori, int tahun_keluaran): Kendaraan(merk, kategori, tahun_keluaran) {
    this->kategori = "Minibus";
}

Minibus::Minibus(const Minibus& b): Kendaraan(b){
    this->kategori = "Minibus";
}

Minibus::~Minibus(){
    cout << "===  Minibus DESTRUCTOR CALLED ===" << endl;
}

Minibus& Minibus::operator=(const Minibus& b){
    this->kategori = b.kategori;
    this->merk = b.merk;
    this->tahun_keluaran = b.tahun_keluaran;
    Kendaraan::no_kendaraan++; 
    return *this;
}

void Minibus::printinfo() const {
    Kendaraan::printinfo();
}

int Minibus::biayaSewa(int lamaSewa) {
    return Kendaraan::biayaSewa(lamaSewa) - this->diskon(lamaSewa);
}

int Minibus::diskon(int lamaSewa) {
    if(lamaSewa > 10){
        return 0.1 * this->biayaSewa(lamaSewa);
    }
    return 0;
}
