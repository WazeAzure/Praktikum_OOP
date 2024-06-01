#include <iostream>
#include "sekretaris.h"
#include "exception.h"

/*
    Membuat objek Sekretaris dengan nilai kertas dan tinta
    default. Besar energi awal adalah ENERGI_MAX
*/
Sekretaris::Sekretaris() {
    this->kertas = KERTAS_DEFAULT;
    this->tinta = TINTA_DEFAULT;
    this->energi = ENERGI_MAX;
    this->memoLength = 0;
    this->memo = new Memo[this->memoLength];
}
/*
    Membuat objek Sekretaris dengan nilai kertas dan tinta
    sesuai yang diberikan. Besar energi awal adalah ENERGI_MAX
*/
Sekretaris::Sekretaris(int kertas, int tinta) {
    this->kertas = kertas;
    this->tinta = tinta;
    this->energi = ENERGI_MAX;
    this->memoLength = 0;
    this->memo = new Memo[this->memoLength];
}
/*
    Dealokasi variabel-variabel yang perlu didealokasi.
    Jika tidak perlu, hapus metode ini.
*/
Sekretaris::~Sekretaris() {
    delete [] this->memo;
}

/*
    Membuat memo dengan isi sesuai yang diberikan. Metode ini
    menggunakan metode pakaiKertas, pakaiTinta, dan pakaiEnergi.
    Untuk membuat 1 memo akan menghabiskan 1 kertas, 1 energi,
    dan tinta sebanyak jumlah karakter pesan.

    Ada beberapa penyebab memo gagal dibuat, yaitu:
    - Jika kertas habis, akan mengeluarkan pesan dari exception,
        ditambah dengan ", segera isi kertas"
    - Jika tinta kurang, akan mengeluarkan pesan dari exception,
        ditambah dengan ", segera isi tinta"
    - Jika energi habis, akan mengeluarkan pesan dari exception,
        ditambah dengan ", segera istirahat"
    - Jika pesan terlalu panjang, akan mengeluarkan pesan dari
        exception, ditambah dengan ", perpendek pesannya"

    Jika memo gagal dibuat, maka tinta, kertas, dan energi tidak
    berkurang. Gunakan metode batalPakaiKertas, batalPakaiTinta,
    dan batalPakaiEnergi.

    Jika berhasil, maka memo akan dimasukkan ke daftar memo serta
    menampilkan pesan "Memo [<nomor_memo>] untuk <untuk> berhasil
    dibuat"

    Keterangan:
    <...> -> ganti dengan nilai yang sesuai.
*/
void Sekretaris::buatMemo(string pesan, string untuk) {
    try {
        pakaiKertas();
        pakaiTinta(pesan.length());
        pakaiEnergi();
        Memo m(pesan, untuk);
        // Proses bikin memo
        // bikin temp
        Memo* temp = new Memo[this->memoLength];
        // nyalin ke temp
        for (int i = 0; i < this->memoLength; i++) {
            temp[i] = this->memo[i];
        }
        
        // alokasi ulang dengan ukuran + 1
        delete [] this->memo;

        this->memoLength++; // jangan lupa
        this->memo = new Memo[this->memoLength];
        // balikin dari temp
        for (int i = 0; i < this->memoLength-1; i++) {
            this->memo[i] = temp[i];
        }
        // nambahin judul baru
        this->memo[this->memoLength-1] = m;
        delete [] temp;

        cout << "Memo [" << this->memoLength << "] untuk " << untuk << " berhasil dibuat" << endl;

    } catch (KertasHabisException e) {
        cout << e.what() << ", segera isi kertas" << endl;
        /* batalPakaiTinta(pesan.length());
        batalPakaiEnergi(); */
    } catch (TintaKurangException e) {
        cout << e.what() << ", segera isi tinta" << endl;
        batalPakaiKertas();
        // batalPakaiEnergi()
    } catch (EnergiHabisException e) {
        cout << e.what() << ", segera istirahat" << endl;
        batalPakaiKertas();
        batalPakaiTinta(pesan.length());
    } catch (PesanKepanjanganException e) {
        cout << e.what() << ", perpendek pesannya" << endl;
        batalPakaiKertas();
        /* batalPakaiTinta(pesan.length());
        batalPakaiEnergi(); */
    }
}
/*
    Menggunakan 1 kertas.

    Jika kertas tidak cukup, maka metode ini akan melemparkan
    KertasHabisException dan tidak ada kertas yang digunakan.
*/
void Sekretaris::pakaiKertas() {
    if (this->kertas >= 1) {
        this->kertas--;
    } else {
        KertasHabisException e;
        throw e;
    }
}
/*
    Menggunakan tinta sebanyak num.

    Jika tinta tidak cukup, maka metode ini akan melemparkan
    TintaKurangException dan tidak ada tinta yang digunakan.
*/
void Sekretaris::pakaiTinta(int num) {
    if (num > 50) {
        PesanKepanjanganException e;
        throw e;
    } else {
        if (this->tinta >= num) {
            this->tinta -= num;
        } else {
            TintaKurangException e;
            throw e;
        }
    }
}
/*
    Menggunakan 1 energi.

    Jika energi tidak cukup, maka metode ini akan melemparkan
    EnergiHabisException dan tidak ada energi yang digunakan.
*/
void Sekretaris::pakaiEnergi() {
    if (this->energi >= 1) {
        this->energi--;
    } else {
        EnergiHabisException e;
        throw e;
    }
}
/*
    Membatalkan penggunaan 1 kertas.
*/
void Sekretaris::batalPakaiKertas() {
    this->kertas++;
}
/*
    Membatalkan penggunaan tinta sebanyak num.
*/
void Sekretaris::batalPakaiTinta(int num) {
    this->tinta += num;
}
/*
    Membatalkan penggunaan 1 energi.
*/
void Sekretaris::batalPakaiEnergi() {
    this->energi++;
}
/*
    Menambahkan jumlah tinta sebanyak num.
*/
void Sekretaris::isiTinta(int num) {
    this->tinta += num;
}
/*
    Menambahkan jumlah kertas sebanyak num.
*/
void Sekretaris::isiKertas(int num) {
    this->kertas += num;
}
/*
    Istirahat mengembalikan energi menjadi maksimum.
*/
void Sekretaris::istirahat() {
    this->energi = ENERGI_MAX;
}
/*
    Menampilkan status dari sekretaris. Berikut adalah format tampilan:
    <...> -> tampilkan nilai yang sesuai
    (...) -> komentar, tidak termasuk output

    --------------
    Status
        Energi : <jumlah_energi>
        Tinta : <jumlah_tinta>
        Kertas : <jumlah_kertas>
        Memo : <jumlah_memo>
        (untuk setiap memo ke-i, mulai dari 1)
        Memo [<i>]
            Pesan : <pesan_memo_i>
            Untuk : <untuk_memo_i>
    --------------

    (Output tidak termasuk ---------- di awal dan akhir)
*/
void Sekretaris::printStatus() {
    cout << "Status" << endl;
    cout << "  Energi : " << this->energi << endl;
    cout << "  Tinta : " << this->tinta << endl;
    cout << "  Kertas : " << this->kertas << endl;
    cout << "  Memo : " << this->memoLength << endl;
    for (int i = 0; i < this->memoLength; i++) {
        cout << "    Memo [" << i+1 << "]" << endl;
        cout << "      Pesan : " << this->memo[i].getPesan() << endl;
        cout << "      Untuk : " << this->memo[i].getUntuk() << endl;
    }
}