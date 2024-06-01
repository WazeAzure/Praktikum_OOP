public class Palindrome<T> {
    //Method untuk mengecek apakah Deque dq merupakan palindrome
    //Deque dq merupakan palindrome jika elemen-elemen pada Deque dq dapat dibaca sama dari depan dan belakang
    public boolean isPalindrome(Deque<T> dq){
        Deque<T> temp1 = new Deque<T>(dq);
        Deque<T> temp2 = new Deque<T>(dq);

        // System.err.println(dq.isEmpty());
        temp2.reverse();
        // System.err.println(dq.isEmpty());

        // System.err.println(dq.lastElmIdx);

        int size = temp1.lastElmIdx;
        for(int i=0; i<size; i++){
            try {
                if(temp1.popFront() != temp2.popFront()){
                    return false;
                }
            } catch (Exception e){
                System.err.println(e);
            }
        }
        return true;
    }

    // public static void main(String[] args) {
    //     Palindrome<Integer> pal = new Palindrome<>();
    //     Deque<Integer> dq = new Deque<>();

    //     try {
    //         dq.pushFront(0);
    //         dq.pushFront(1);
    //         dq.pushFront(2);
    //         dq.pushFront(3);
    //         dq.pushFront(2);
    //         dq.pushFront(1);
    //         dq.pushFront(0);
    //     } catch (Exception e){
    //         System.err.println(e);
    //     }

    //     System.err.println(pal.isPalindrome(dq));

    // }
}