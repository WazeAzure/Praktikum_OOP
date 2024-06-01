#ifndef __KENDARAAN_VIRTUAL_H__
#define __KENDARAAN_VIRTUAL_H__

#include <iostream>

using namespace std;

class Kendaraan {
	private:
		string kategori;
		string merk;
		int tahun_keluaran;
		const int id;
		static int no_kendaraan;
	public:
		Kendaraan();
		Kendaraan(string merk, string kategori, int tahun_keluaran);
		Kendaraan(const Kendaraan&);
		~Kendaraan();
		Kendaraan& operator=(const Kendaraan&);

		virtual void printinfo() const = 0;
		virtual int biayaSewa(int lamaSewa) = 0;
};

class Bus : protected Kendaraan {
    private:
        int kapasitas;
    public:
		Bus();
		Bus(string merk, string kategori, int tahun_keluaran);
		Bus(const Kendaraan&);
		~Bus();
		Bus& operator=(const Kendaraan&);

		void printinfo() const;
		int biayaSewa(int lamaSewa);
};

class Mobil : protected Kendaraan {
	private:
		string supir;
	public:
		Mobil();
		Mobil(string merk, string kategori, int tahun_keluaran);
		Mobil(const Kendaraan&);
		~Mobil();
		Mobil& operator=(const Kendaraan&);
		void printinfo() const;
		int biayaSewa(int lamaSewa);
};

#endif


