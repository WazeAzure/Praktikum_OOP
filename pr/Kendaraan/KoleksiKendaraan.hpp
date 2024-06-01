#ifndef __KOLEKSI_KENDARAAN_H__
#define __KOLEKSI_KENDARAAN_H__

#include "Kendaraan.hpp"

class KoleksiKendaraan {
    private:
        Kendaraan **arr;
        int size;
    public:
        int neff;
        KoleksiKendaraan();
        KoleksiKendaraan(int size);
        KoleksiKendaraan(const KoleksiKendaraan&);
        ~KoleksiKendaraan();

        KoleksiKendaraan& operator=(const KoleksiKendaraan&);

        void printAll() const;
        void operator<<( Kendaraan& k);
        void operator<<(const KoleksiKendaraan& kk2);

};

#endif