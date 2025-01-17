import java.lang.Comparable;

class MataKuliah implements Comparable<MataKuliah> {
  private float rating;
  private String nama;
  private int kodeJurusan;
  private int tahunPengambilan; 

  public MataKuliah(String nama, int kodeJurusan, int tahunPengambilan, float rating) {
    this.nama = nama;
    this.kodeJurusan = kodeJurusan;
    this.tahunPengambilan = tahunPengambilan;
    this.rating = rating;
  }

  public String getNama(){
    return this.nama;
  }

  public int getKodeJurusan(){
    return this.kodeJurusan;
  }

  public int getTahunPengambilan(){
    return this.tahunPengambilan;
  }

  public float getRating(){
    return this.rating;
  }

  public int compareTo(MataKuliah m) {
    // compareTo mengembalikan:
    // 0 bila this sama dengan m
    // 1 bila this lebih dari m
    // -1 bila this kurang dari m
    if (this.kodeJurusan == m.kodeJurusan) {
        if (this.tahunPengambilan == m.tahunPengambilan) {
            if (this.rating == m.rating) {
                return 0;
            } else {
                return this.rating > m.rating ? 1 : -1;
            }
        } else {
            return this.tahunPengambilan > m.tahunPengambilan ? 1 : -1;
        }
    } else {
        return this.kodeJurusan > m.kodeJurusan ? 1 : -1;
    }
  }
}