import java.util.*;

public class Pasukan {
    private List<Integer> li;
    private int n;

    public Pasukan(List<Integer> l, int n){
        this.li = l;
        this.n = n;
    }

    public void reset(){
        this.li.clear();
        for(int i=0; i<this.n; i++){
            this.li.add(0);
        }
    }

    public long get (int idx) {
        reset();
        long start = Util.getTime();
        Integer val = this.li.get(idx);
        long finish = Util.getTime();
        return finish - start;
    }

    public long del (int idx, int t) {
        reset();
        long start = Util.getTime();
        for (int i = 0; i < t; i++) {
            this.li.remove(idx);
        }
        long finish = Util.getTime();
        return finish - start;
    }
}
