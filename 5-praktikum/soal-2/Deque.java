import java.util.ArrayList;
import java.util.List;

// Class Deque berikut merupakan suatu kelas Generic yang merepresentasikan suatu Deque.
// Deque merupakan suatu struktur data yang mirip dengan Queue, namun Deque memiliki dua ujung, yaitu front dan back.
// Deque disimpan dengan memanfaatkan ArrayList.
// Elemen front pada Deque disimpan pada indeks paling kiri, sedangkan elemen back disimpan pada indeks paling kanan.
public class Deque<T> {

  private List<T> data;

  public int lastElmIdx, size;

  private final static int DEFAULT_Deque_SIZE = 500;


  //Constructor dengan size default
  public Deque(){
    this.size = DEFAULT_Deque_SIZE;
    this.lastElmIdx = -1;
    this.data = new ArrayList<T>();
  }

  //Constructor dengan size = n
  public Deque(int n){
    this.size = n;
    this.lastElmIdx = -1;
    this.data = new ArrayList<T>();
  }

  //Copy Constructor dari Deque lain
  public Deque(final Deque<T> q){
    this.size = q.size;
    this.lastElmIdx = q.lastElmIdx;
    this.data = new ArrayList<T>(q.data);
  }

  //Method untuk menambahkan elemen pada ujung front Deque
  //Jika Deque penuh, lempar exception "Deque is full"
  public void pushFront(T t) throws Exception {
    if(isFull()){
      throw new Exception("Deque is full");
    }
    this.data.add(0, t);
    this.lastElmIdx++;
  }

  //Method untuk menambahkan elemen pada ujung back Deque
  //Jika Deque penuh, lempar exception "Deque is full"
  public void pushBack(T t) throws Exception {
    if(isFull()){
      throw new Exception("Deque is full");
    }
    this.lastElmIdx++;
    this.data.add(this.lastElmIdx, t);
  }

  //Method untuk menghapus elemen pada ujung front Deque
  //Jika Deque kosong, lempar exception "Deque is empty"
  public T popFront() throws Exception {
    if(isEmpty()){
      throw new Exception("Deque is empty");
    }
    T element = this.data.remove(0);
    this.lastElmIdx--;
    return element;
  }

  //Method untuk menghapus elemen pada ujung back Deque
  //Jika Deque kosong, lempar exception "Deque is empty"
  public T popBack() throws Exception {
    if(isEmpty()){
      throw new Exception("Deque is empty");
    }
    T element = this.data.remove(this.lastElmIdx);
    this.lastElmIdx--;
    return element;
  }

  //Method untuk membalikkan urutan elemen pada Deque
  public void reverse() {
    for(int i=0; i<this.lastElmIdx/2; i++){
      T temp = this.data.get(i);
      this.data.set(i, this.data.get(this.lastElmIdx-i));
      this.data.set(this.lastElmIdx-i, temp);
    }
  }

  //Method untuk mengecek apakah Deque kosong
  public boolean isEmpty() {
    return this.lastElmIdx == -1;
  }
  
  //Method untuk mengecek apakah Deque penuh
  public boolean isFull() {
    return this.lastElmIdx >= this.size-1;
  }

  //Method untuk mendapatkan ukuran Deque
  public int size() {
    return this.size;
  }
}