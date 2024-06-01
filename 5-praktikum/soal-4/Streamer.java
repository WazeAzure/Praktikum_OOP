import java.util.ArrayList;
import java.util.List;
import java.util.function.Function;

public class Streamer<T> implements IStreamer<T> {

    private List<T> data;

    public Streamer(List<T> data) {
        this.data = new ArrayList<>(data);
    }

    public void forEach(Function<T, Void> consumer) {
        for(T elmt: this.data){
            consumer.apply(elmt);
        }
    }

    public <R> IStreamer<R> map(Function<T, R> mapper) {
        Streamer<R> temp = new Streamer<>(new ArrayList<>());
        for (T a : this.data) {
            temp.data.add(mapper.apply(a));
        }
        return temp;
    }

    public IStreamer<T> filter(Function<T, Boolean> predicate) {
        Streamer<T> temp = new Streamer<>(new ArrayList<>());
        for(T elmt : this.data){
            if(predicate.apply(elmt)){
                temp.data.add(elmt);
            }
        }

        return temp;
    }

    public <R> R reduce(R initialValue, Function<R, Function<T, R>> reducer) {
        R temp = initialValue;
        for (T a : this.data) {
            temp = reducer.apply(temp).apply(a);
        }
        return temp;
    }

    public <R> IStreamer<R> flatMap(Function<T, IStreamer<R>> mapper) {
        Streamer<R> temp = new Streamer<>(new ArrayList<>());
        for (T a : this.data) {
            mapper.apply(a).forEach((x) -> {temp.data.add(x); return null;});
        }
        return temp;
    }

    public T findFirst(Function<T, Boolean> predicate) {
        for(T elmt: this.data){
            if(predicate.apply(elmt)){
                return elmt;
            }
        }
        return null;
    }

    public T findLast(Function<T, Boolean> predicate) {
        for(int i=this.data.size()-1; i>-1; i--){
            if(predicate.apply(this.data.get(i))){
                return this.data.get(i);
            }
        }
        return null;
    }

    public T head() {
        if(!isEmpty()){
            return this.data.get(0);
        }
        return null;
    }

    public IStreamer<T> tail() {
        if (!isEmpty()) {
            Streamer<T> temp = new Streamer<>(this.data);
            temp.data.remove(0);
            return temp;
        }
        return new Streamer<>(new ArrayList<>());
    }

    public T last() {
        if(!isEmpty()){
            return this.data.get(this.data.size()-1);
        }
        return null;
    }

    public IStreamer<T> init() {
        if (!isEmpty()) {
            Streamer<T> temp = new Streamer<>(this.data);
            temp.data.remove(this.data.size()-1);
            return temp;
        }
        return new Streamer<>(new ArrayList<>());
    }

    public IStreamer<T> takeFirst(int n) {
        if(n > this.data.size()){
            n = this.data.size();
        }
        return new Streamer<T>(new ArrayList<>(this.data.subList(0, n)));
    }

    public IStreamer<T> takeLast(int n) {
        Streamer<T> temp = new Streamer<>(new ArrayList<>());
        if (n > this.data.size()) {
            n = this.data.size();
        }
        for (int i = this.data.size()-1; i >= this.data.size() - n; i--) {
            temp.data.add(this.data.get(i));
        }
        temp.reverse();
        return temp;
    }

    public Boolean isEmpty() {
        return this.data.isEmpty();
    }

    public Integer count() {
        return this.data.size();
    }

    public Boolean some(Function<T, Boolean> predicate) {
        for(T elmt: this.data){
            if(predicate.apply(elmt)){
                return true;
            }
        }
        return false;
    }

    public Boolean every(Function<T, Boolean> predicate) {
        for(T elmt: this.data){
            if(!predicate.apply(elmt)){
                return false;
            }
        }
        return true;
    }

    public List<T> collect() {
        List<T> temp = new ArrayList<>(data);
        return temp;
    }

    public void reverse() {
        List<T> temp = new ArrayList<>();
        for (int i = this.data.size()-1; i >= 0; i--) {
            temp.add(this.data.get(i));
        }
        this.data = temp;
    }
}