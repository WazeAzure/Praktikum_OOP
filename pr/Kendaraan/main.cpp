#include "KoleksiKendaraan.hpp"

int main(){
    KoleksiKendaraan k(4);
    Bus d("d2", "Bus", 19, 10);

    Minibus *a = new Minibus();

    KoleksiKendaraan k2(4);
    Mobil e("e2", "Mobil", 1, "edbert");


    k << d;
    k << *a;
    k2 << e;

    cout << "neff k dan k2: "<< k.neff << " " << k2.neff << endl;
    k << k2;

    cout << "k neff: " << k.neff << endl;

    k.printAll();

}