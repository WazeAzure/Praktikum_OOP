import java.lang.reflect.*;

public class MahasiswaDecoder {
    private Mahasiswa mahasiswa;

    MahasiswaDecoder(Mahasiswa mahasiswa) {
        this.mahasiswa = mahasiswa;
    }

    public void addMatkul(String name) throws Exception {
        Method method = Mahasiswa.class.getDeclaredMethod("addMatkul", String.class);
        method.setAccessible(true);
        method.invoke(this.mahasiswa, name);
    }

    public int getNIM() throws Exception {
        Field nim = Mahasiswa.class.getDeclaredField("NIM");
        nim.setAccessible(true);
        return (int) nim.get(this.mahasiswa);
    }

    public double getIPK() throws Exception {
        Field ipk = Mahasiswa.class.getDeclaredField("IPK");
        ipk.setAccessible(true);
        return (double) ipk.get(this.mahasiswa);
    }
}