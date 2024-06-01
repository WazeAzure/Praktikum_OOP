

class Kendaraan {
    protected String merk;
    protected int tahun_keluaran;
    protected int no_kendaraan;
    protected String kategori;


    Kendaraan(){
        this.merk = "XXX";
        this.tahun_keluaran = 0;
        this.kategori = "mobil";
        no_kendaraan = 0;
    }

    Kendaraan(int nomor, int tahun_keluaran, String merk, String kategori){
        this.no_kendaraan = nomor;
        this.merk = merk;
        this.tahun_keluaran = tahun_keluaran;
        this.kategori = kategori;
    }

    public void printInfo(){
        System.out.printf("No Kendaraan\t\t: %d\nKategori\t\t: %s\nTahun Keluaran\t\t: %d\nMerk\t\t\t: %s\n", this.no_kendaraan, this.kategori, this.tahun_keluaran, this.merk);
    }
    public double biayaSewa(int lamaSewa){
        if(this.kategori == "Bus"){
            return 1000000 * lamaSewa;
        } else if(this.kategori == "MiniBus"){
            if (lamaSewa <= 5){
                return 5000000;
            } else {
                return 5000000 + 500000 * (lamaSewa - 5);
            }
        } else {
            return 500000 * lamaSewa;
        }
    }
}

class Bus extends Kendaraan {
    private int kapasitas;

    public Bus(){
        this.kapasitas = 0;
        this.kategori = "Bus";
    }

    public Bus(int nomor, int tahun_keluaran, String merk, String kategori, int kapasitas){
        super(nomor, tahun_keluaran, merk, kategori);
        this.kapasitas = kapasitas;
    }
    
    public void printInfo(){
        super.printInfo();
        System.out.println("Kapasitas\t\t: " + kapasitas);    
    }
}

class Mobil extends Kendaraan {
    private String supir;

    public Mobil(){
        this.supir = "XXXX";
    }

    public Mobil(int nomor, int tahun_keluaran, String merk, String kategori, String supir){
        super(nomor, tahun_keluaran, merk, kategori);
        this.supir = supir;
    }
    
    public void printInfo(){
        super.printInfo();
        System.out.println("Supir\t\t: " + supir);    
    }
}

class Minibus extends Kendaraan {
    public Minibus(){
        this.kategori = "Minibus";
    }

    public Minibus(int nomor, int tahun_keluaran, String merk, String kategori){
        super(nomor, tahun_keluaran, merk, kategori);
    }

    public double biayaSewa(int lamaSewa){
        return super.biayaSewa(lamaSewa) - this.diskon(lamaSewa);
    }

    public double diskon(int lamaSewa){
        if(lamaSewa > 10){
            return 0.1 * this.biayaSewa(lamaSewa);
        }
        return 0;
    }
}

class KoleksiKendaraan {
    private Kendaraan list_Kendaraans[];
    private int neff;

    public KoleksiKendaraan(){
        this.list_Kendaraans = new Kendaraan[100];
        this.neff = 0;
    }

    public KoleksiKendaraan(int capacity){
        this.list_Kendaraans = new Kendaraan[capacity];
        this.neff = 0;
    }

    public void printAll(){
        for(int i=0; i<this.neff; i++){
            this.list_Kendaraans[i].printInfo();
        }
    }

    public void add(Kendaraan k){
        this.list_Kendaraans[neff] = k;
        this.neff++;
    }

    public void add(KoleksiKendaraan kk){
        int capacity = this.list_Kendaraans.length;
        int i = 0;
        while(this.neff != capacity && i != kk.list_Kendaraans.length){
            this.add(kk.list_Kendaraans[i]);
            i++;
        }
    }
}

public class KendaraanJava {
    public static void main(String[] args){
        Minibus k = new Minibus(1, 2004, "AWIKWOK", "Minibus");
        Kendaraan k2 = new Kendaraan(2, 2004, "Merk1", "Bus");
        Bus k3 = new Bus();
        Mobil k4 = new Mobil(4, 2024, "MERK2", "Mobil", "Edbert");
        KoleksiKendaraan kk = new KoleksiKendaraan();

        kk.add(k2);
        kk.add(k);
        kk.add(k3);
        kk.add(k4);

        kk.printAll();

        // System.out.println("Hello World");
    }
}