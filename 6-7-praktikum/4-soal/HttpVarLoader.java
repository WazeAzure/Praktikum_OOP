import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.HashMap;
import java.util.Objects;

public class HttpVarLoader {

  private HashMap<String, String> headers;
  private HashMap<String, String> body;
  private HashMap<String, String> query;
  private HashMap<String, String> cookie;

  /**
   * Variabel HTTP direpresentasikan dengan HashMap key-value.
   * Asumsikan:
   * - Tidak mungkin ada key berupa null
   * - Value mungkin null
   * 
   * @param headers
   * @param body
   * @param query
   * @param cookie
   */
  public HttpVarLoader(HashMap<String, String> headers, HashMap<String, String> body, HashMap<String, String> query, HashMap<String, String> cookie) {
    this.headers = new HashMap<>(headers);
    this.body = new HashMap<>(body);
    this.query = new HashMap<>(query);
    this.cookie = new HashMap<>(cookie);
  }

  /**
   * Melakukan load variabel HTTP terhadap objek pada atribut dan method yang
   * menggunakan annotation HttpVar
   * 
   * @param obj Objek
   * @throws NullPointerException      Jika parameter obj bernilai null, atau jika
   *                                   nama variabel yang diminta tidak ada pada
   *                                   daftar variabel HTTP. Throw exception ini
   *                                   tanpa string message apapun.
   * @throws InvocationTargetException Jika method yang dipanggil meng-throw
   *                                   exception. Perhatikan bahwa Method.invoke()
   *                                   meng-throw exception ini.
   */
  public void load(Object obj) throws NullPointerException, InvocationTargetException {
    if(obj == null){
      throw new NullPointerException();
    }

    for(Field field: obj.getClass().getDeclaredFields()){
      if(field.isAnnotationPresent(HttpVar.class)){
          HttpVar httpVar = field.getAnnotation(HttpVar.class);
          String value = getValue(httpVar.type(), httpVar.name());
          if(value == null && !isKeyExist(httpVar)){
              throw new NullPointerException();
          }
          try{
              field.setAccessible(true);
              field.set(obj, value);
          }catch(IllegalAccessException e){
              throw new RuntimeException();
          }
      }
  }
 
  Method[] m = obj.getClass().getDeclaredMethods();

  for(Method method: m){
      if(method.isAnnotationPresent(HttpVar.class)){

          HttpVar httpVar = method.getAnnotation(HttpVar.class);
          String value = getValue(httpVar.type(), httpVar.name());
          if(value == null && !isKeyExist(httpVar)){
              throw new NullPointerException();
          }
          try{
              method.setAccessible(true);
              method.invoke(obj, value);
          }catch(IllegalAccessException e){
              throw new RuntimeException();
          }catch(InvocationTargetException e){
              throw e;
          }
      }
  }
}

  public String getValue(HttpVar.Type type, String name){
    switch (type) {
        case Header:
          return headers.get(name);
        case Body:
          return body.get(name);
        case Query:
          return query.get(name);
        case Cookie:
          return cookie.get(name);
        default:
          return null;
      }
  }
  private boolean isKeyExist(HttpVar httpVar) {
    switch (httpVar.type()) {
      case Header:
        return headers.containsKey(httpVar.name());
      case Body:
        return body.containsKey(httpVar.name());
      case Query:
        return query.containsKey(httpVar.name());
      case Cookie:
        return cookie.containsKey(httpVar.name());
      default:
        return false;
    }
  }
}