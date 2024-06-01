#ifndef __KENDARAAN_H__
#define __KENDARAAN_H__

#include <iostream>

using namespace std;

class Kendaraan {
	protected:
		string merk;
		int tahun_keluaran;
		const int id;
		static int no_kendaraan;
	public:
		string kategori;
		Kendaraan();
		Kendaraan(string merk, string kategori, int tahun_keluaran);
		Kendaraan(const Kendaraan&);
		~Kendaraan();
		Kendaraan& operator=(const Kendaraan&);

		virtual void printinfo() const = 0;
		virtual int biayaSewa(int lamaSewa) = 0;
};

class Bus : public Kendaraan {
    private:
        int kapasitas;
    public:
		Bus();
		Bus(string merk, string kategori, int tahun_keluaran, int kapasitas);
		Bus(const Bus&);
		~Bus();
		Bus& operator=(const Bus&);
		void printinfo() const override;
		int biayaSewa(int lamaSewa) override;
};

class Mobil : public Kendaraan {
    private:
        string supir;
    public:
		Mobil();
		Mobil(string merk, string kategori, int tahun_keluaran, string supir);
		Mobil(const Mobil&);
		~Mobil();
		Mobil& operator=(const Mobil&);
		void printinfo() const override;
		int biayaSewa(int lamaSewa) override;
};

class Minibus : public Kendaraan {
    public:
		Minibus();
		Minibus(string merk, string kategori, int tahun_keluaran);
		Minibus(const Minibus&);
		~Minibus();
		Minibus& operator=(const Minibus&);
		void printinfo() const override;
		int biayaSewa(int lamaSewa) override;
		int diskon(int lamaSewa);
};

#endif
