public class Main {
    public static void main(String Args[]){
        System.out.println("hello world");
        
        Kompleks k = new Kompleks(-3, -2);
        Kompleks j = new Kompleks(2, 1);

        k.print();
        int x = Kompleks.countKompleksInstance();
        System.out.println(x);
    }
}
