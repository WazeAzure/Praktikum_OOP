#include <iostream>
#include "RestoranRamen.hpp"
using namespace std;

// Menambah jumlah order yang dipesan oleh meja n, dengan harga p
// Jika meja sudah diisi maka akan menambah total yang telah dipesan
void RestoranRamen::tambahOrder(int n, int p) {
    auto itr = daftarMeja.find(n);
    if (itr == daftarMeja.end()) {
        // Meja belum ada, maka tambah meja dan order
        daftarMeja.insert(pair<int,int>(n, p));
    } else {
        // Meja sudah ada, tambah totalnya
        daftarMeja[n] += p;
    }
}

// Mengembalikan total harga pesanan pada meja n, menghapus entri untuk meja tersebut
int RestoranRamen::tutupOrder(int n) {
    int total = daftarMeja[n];
    daftarMeja.erase(n);
    return total;
}

// Mengembalikan total harga pesanan pada meja n
int RestoranRamen::cekTotal(int n) {
    return daftarMeja[n];
}

// Mengembalikan jumlah meja yang terisi saat itu
// Restoran mungkin kosong
int RestoranRamen::totalMeja() {
    int count = 0;
    for (auto i : daftarMeja) {
        count++;
    }
    return count;
}

// Mencetak semua meja yang terisi pada restoran diakhiri dengan new line
// Contoh : 
/*
    Meja 1 = 5000
    Meja 2 = 3000
    Meja 4 = 10000
*/
// Jika restoran kosong akan mencetak "Restoran kosong" diakhiri new line
void RestoranRamen::cetakMeja() {
    if (totalMeja() == 0) {
        cout << "Restoran kosong" << endl;
    } else {
        for (auto i : daftarMeja) {
            cout << "Meja " << i.first << " = " << i.second << endl;
        }
    }
}