public class Result<T, E extends Exception> implements IResult<T, E> {
    private T data;
    private E error;
  
    // return new Result object with data based on input
    public static <T, E extends Exception> Result<T, E> ok(T data) {
        Result<T, E> newRes = new Result();
        newRes.data = data;
        return newRes; 
    }
  
    // return new Result object with error based on input
    public static <T, E extends Exception> Result<T, E> err(E error) {
        Result<T, E> newRes = new Result();
        newRes.error = error;
        return newRes; 
    }
  
    // implement all other functions in the interface
    public boolean isOk(){
        return this.data != null;
    }

    public boolean isErr(){
        return this.error != null;
    }

    public T unwrap() throws Exception {
        if(isOk()){
            return this.data;
        }
        throw this.error;
    }

    public T unwrapOrElse(T defaultValue){
        if(isOk()){
            return this.data;
        }
        return defaultValue;
    }

    public T unwrapOrThrow(Exception defaulException) throws Exception {
        if(isOk()){
            return this.data;
        }
        throw defaulException;
    }
  }