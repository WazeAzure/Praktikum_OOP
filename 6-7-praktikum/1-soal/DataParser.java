import java.util.ArrayList;
import java.util.List;

public class DataParser {
    private static List<String> validCountryCodes = new ArrayList<String>(); // Note: Country Code mungkin saja ditambah. Format country code selalu +XX

    public DataParser() {
        validCountryCodes.add("+62");
    }

    public void addCountryCode(String code) {
        validCountryCodes.add(code);
    }

    // Return true apabila phone valid. Panjang phone number yang valid minimal 8 dan maksimal 10 angka setelah country code.
    // Apabila country code tidak ditemukan di list of validCountryCodes, throw InvalidCountryException
    // Apabila panjang nomor tidak valid, throw InvalidPhoneLengthException
    // Tips: Gunakan StringBuilder
    public boolean parsePhone(String phone) throws InvalidCountryException, InvalidPhoneLengthException {
        // panjang len
        if(phone.charAt(0) != '+'){
            throw new InvalidCountryException();
        }

        boolean country_code = false;
        for(int i=0; i<validCountryCodes.size(); i++){
            if(phone.startsWith(validCountryCodes.get(i))){
                country_code = true;
                break;
            }
        }

        if(!country_code){
            throw new InvalidCountryException();
        }

        if(phone.length()-3 >= 8 && phone.length()-3 <= 10){
            return true;
        } else {
            throw new InvalidPhoneLengthException();
        }
    }

    // Return true apabila email valid. Email yang valid adalah email dengan format *@*.*
    // A@gmail.co.com.id adalah email yang valid
    // A.B.C@mail.co adalah email yang valid
    // @gmail.com tidak valid dan akan throw InvalidEmailUserException
    // A@gmail tidak valid dan akan throw InvalidEmailDomainException
    // Algoritma akan mengecek username terlebih dahulu sebelum mengecek domain dari email
    // Dipastikan ada satu @
    public boolean parseEmail(String email) throws InvalidEmailUserException, InvalidEmailDomainException {
        if(email.charAt(0) == '@'){
            throw new InvalidEmailUserException();
        }

        int at_location = 0;
        boolean dot_after_at = false;
        for(int i=0; i<email.length(); i++){
            if(at_location != 0){
                if(email.charAt(i) == '.'){
                    dot_after_at = true;
                    break;
                }
            }
            if(email.charAt(i) == '@'){
                at_location = i;
            }
        }

        if(!dot_after_at || email.endsWith(".")){
            throw new InvalidEmailDomainException();
        }

        return true;
    }
    
}
