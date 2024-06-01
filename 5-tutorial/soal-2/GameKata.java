import java.util.*;

public class GameKata {
    public static void run(String[] tito, String[] wiwid) {
         // Inisiasi Hashmap
         Map<String,Boolean> mt = new HashMap<String,Boolean>();
         Map<String,Boolean> mw = new HashMap<String,Boolean>();
 
         // Melakukan pemrosesan terhadap kata yang disampaikan tito
         for (String x : tito) {
             if (mt.containsKey(x)) {
                mt.put(x, mt.get(x));
             } else {
                mt.put(x, true);
             }
         }
         
         // Melakukan pemrosesan terhadap kata yang disampaikan wiwid
         for (String x : wiwid) {
             if (mw.containsKey(x)) {
                mw.put(x, mw.get(x));
             } else {
                mw.put(x, true);
             }
         }

         for (Map.Entry<String, Boolean> e : mw.entrySet()) {
             if (mt.containsKey(e.getKey())) {
                 System.out.println(e.getKey());
             }
         }
    }

    // public static void main(String[] args){
    //     String[] s1 = {"a", "d", "A"};
    //     String[] s2 = {"b", "c", "a"};
    //     run(s1, s2);
    // }
}
