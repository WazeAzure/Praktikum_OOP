import java.lang.reflect.*;
import java.util.ArrayList;
import java.util.List;

public class Reflection {
    //TIDAK BOLEH MENGUBAH NAMA METHOD YANG SUDAH ADA DAN PARAMS SERTA INPUT TYPENYA
    //BOLEH MENAMBAHKAN PRIVATE / PROTECTED METHOD SESUAI DENGAN KEBUTUHAN
    //DI LUAR SANA ADA KELAS YANG NAMANYA Ghost DAN Secret.

    public ArrayList<String> ghostMethods() {
        ArrayList<String> methods = new ArrayList<String>();

        try {
            Class ghostClass = Class.forName("Ghost");
            Method[] ghostMethods = ghostClass.getDeclaredMethods();
            for (Method method : ghostMethods) {
                methods.add(method.getName());
            }
        } catch (ClassNotFoundException e) {
            // catch the exception, prevent using throws
        }

        return methods;
    }   

    public Integer sumGhost() throws Exception {
        Ghost aGhost = new Ghost();
        int sum = 0;
        Class ghostClass = Class.forName("Ghost");
        Method[] ghostMethods = ghostClass.getDeclaredMethods();
        for (Method method : ghostMethods) {
            if (method.getReturnType() == Integer.class || method.getReturnType() == int.class) {
                method.setAccessible(true);
                sum += (int) method.invoke(aGhost);
            }
        }
        return sum;
    }

    public String letterGhost() throws Exception {
        Ghost aGhost = new Ghost();
        StringBuilder result = new StringBuilder();
        Class ghostClass = Class.forName("Ghost");
        Method[] ghostMethods = ghostClass.getDeclaredMethods();
        for (Method method : ghostMethods) {
            if (method.getReturnType() == String.class) {
                method.setAccessible(true);
                result.append(method.invoke(aGhost));
            }
        }
        return result.toString();
    }

    public String findSecretId(List<Secret> sl, String email) throws Exception {
        for (Secret secret : sl) {
            if (secret.isThis(email)) {
                Field uniqueIdField = Secret.class.getDeclaredField("uniqueId");
                uniqueIdField.setAccessible(true);
                return (String) uniqueIdField.get(secret);
            }
        }
        return "NaN";
    }
}