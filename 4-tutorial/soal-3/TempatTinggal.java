public class TempatTinggal {
    protected int luas;
    protected double hargaBahanBangunan;

    public double hitungBiayaBangun(){
        return this.luas * this.hargaBahanBangunan;
    }

    public int getLuas(){
        return this.luas;
    }

    public double getHargaBahanBangunan(){
        return this.hargaBahanBangunan;
    }

    public void setLuas(int luas){
        this.luas = luas;
    }

    public void setHargaBahanBangunan(double hargaBahanBangunan){
        this.hargaBahanBangunan = hargaBahanBangunan;
    }
}

class Rumah extends TempatTinggal {
    public Rumah(int luas, double hargaBahanBangunan){
        this.luas = luas;
        this.hargaBahanBangunan = hargaBahanBangunan;
    }

    public Rumah(int lebarTanah, int panjangTanah, double hargaBahanBangunan){
        this.luas = lebarTanah * panjangTanah;
        this.hargaBahanBangunan = hargaBahanBangunan;
    }

    public double hitungBiayaBangun(double biayaOrmas){
        return super.hitungBiayaBangun() + biayaOrmas;
    }

    public void setLuas(int luas){
        this.luas = luas;
    }

    public void setLuas(int lebarTanah, int panjangTanah){
        this.luas = lebarTanah * panjangTanah;
    }
}

interface Kendaraan {
    public float hitungJarakTempuh();
}

class Karavan extends TempatTinggal implements Kendaraan {
    private float bensin;
    private float pemakaianBensin;

    public double hitungBiayaBangun(){
        return super.hitungBiayaBangun() * 3;
    }

    public float hitungJarakTempuh(){
        return bensin * pemakaianBensin;
    }

    public float getBensin(){
        return this.bensin;
    }

    public float getPemakaianBensin(){
        return this.pemakaianBensin;
    }

    public void setBensin(float bensin){
        this.bensin = bensin;
    }

    public void setPemakaianBensin(float pemakaianBensin){
        this.pemakaianBensin = pemakaianBensin;
    }
}