import java.util.ArrayList;
import java.util.List;

//Class Stack berikut merupakan suatu kelas GENERIC
//Stack disimpan dengan memanfaatkan ArrayList
//Element terakhir stack disimpan pada index paling kanan pada ArrayList
public class Stack<T> {

  private List<T> data;

  private int lastElmIdx, size;

  private final static int DEFAULT_STACK_SIZE = 500;


  //Constructor dengan size default
  public Stack(){
    this.size = DEFAULT_STACK_SIZE;
    this.lastElmIdx = -1;
    this.data = new ArrayList<T>();
  }
  
  //Constructore dengan size = n
  public Stack(int n){
    this.size = n;
    this.lastElmIdx = -1;
    this.data = new ArrayList<T>();
  }

  //Copy constructor dari stack lain
  public Stack(final Stack<T> q){
    this.size = q.size;
    this.lastElmIdx = q.lastElmIdx;
    this.data = new ArrayList<>(q.data);
  }

  //Tambahkan elemen t ke dalam stack
  //Jika stack penuh, lempar exception "Stack is full"
  public void push(T t) throws Exception{
    if(isFull()){
        throw new Exception("Stack is full");
    }
    this.data.add(0, t);
    this.lastElmIdx++;
  }

  //Hapus elemen terakhir dari stack
  //Jika stack kosong, lempar exception "Stack is empty"
  public T pop() throws Exception{
    if(isEmpty()){
        throw new Exception("Stack is empty");
    }
    T ans = this.data.get(0);
    this.data.remove(0);
    this.lastElmIdx--;
    return ans;
  }

  //Cek apakah stack kosong
  public boolean isEmpty(){
    return this.lastElmIdx == -1;
  }

  //Cek apakah stack penuh
  public boolean isFull(){
    return this.lastElmIdx >= size-1;
  }
}