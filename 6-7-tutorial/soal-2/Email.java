public class Email {
    private String email; 
    public Email(String email) {
        this.email = email;
    };
    
    public boolean validateEmail() throws InvalidEmailException, InvalidDomainException {
        /**
         * Implementasi dengan aturan:
         * Aturan email
         * - Email harus mengandung tepat 1 karakter @ ditengah email
         * - Bagian sebelum @ tidak boleh kosong
         * - Bagian email setelah @ harus memiliki tepat 1 buah titik (.)
         * - Email hanya akan mengandung huruf, angka, (@), dan (.). Karakter lain tidak
         * perlu diperiksa
         * 
         * "john@example.com" => Email Valid
         * "jane.doe@gmail.com" => Email Valid
         * "" => mengembalikan pesan "Email tidak boleh kosong"
         * "example.com" => mengembalikan pesan "Email harus mengandung tepat satu buah @"
         * "@example.com" => mengembalikan pesan "@ tidak boleh di awal email"
         * "john@com" => mengembalikan pesan "Email harus memiliki domain yang valid"
         */

        // 1. Email tidak boleh kosong
        if (this.email.length() == 0) {
            throw new InvalidEmailException("Email tidak boleh kosong");
        }

        // 2. Melakukan pembacaan terhadap isi email
        // Intansiasi variabel
        int index = 0;
        int atCount = 0;  // Jumlah @ yang terbaca 

        // 3. Selama belum sampai ujung pembacaan, dan ketemu @, tambahkan saja ke jumlah simbol
        while (index < this.email.length() && atCount == 0) {
            // Cek karakter '@'
            if (this.email.charAt(index) == '@') {
                atCount++;
            } else {
                index++;
            }
        }

        // 4. Kalo gaada simbol yang kebaca salah
        if (atCount == 0) {
            throw new InvalidEmailException("Email harus mengandung tepat satu buah @");
        } 
        // Tapi kalo misal terbaca dan posisinya di awal, salah juga
        else if (index == 0) {
            throw new InvalidEmailException("@ tidak boleh di awal email");
        }

        index++;

        // 5. Pastikan setelah @ hanya ada 1 titik
        // gaboleh ada simbol @ lagi

        // Mulai hitung dengan posisi kedua
        int pos2 = index;
        int dotPos = -1;  // Posisi pertama ditemukan "."
        int dotCount = 0; // jumlah titik yang terbaca

        while (pos2 < this.email.length()) {
            // Cek @
            if (this.email.charAt(pos2) == '@') {
                atCount++;
            } 
            // Cek .
            else if (this.email.charAt(pos2) == '.') {
                // Blm pernah ditemuin
                if (dotPos == -1) {
                    dotPos = pos2;
                }
                // Increment
                dotCount++;
            }
            pos2++;
        }

        // Ingat, @ hanya boleh ada 1
        if (atCount > 1) {
            throw new InvalidEmailException("Email harus mengandung tepat satu buah @");
        }
        // Kalo cuma 1, cek . nya
        // Kondisi fail
        // 1. dotCount nya lebih dari 1
        // 2. dotCount nya 1, tapi posisinya tepat habis @ atau di paling belakang
        else if (dotCount != 1 || (dotCount == 1 && (dotPos == index || dotPos == this.email.length() - 1))) {
            throw new InvalidDomainException();
        }
        
        return true;
    }
}

class InvalidEmailException extends Exception {
    public InvalidEmailException(String message) {
        // Implementasi InvalidEmailException
        super(message);
    }
}

class InvalidDomainException extends Exception {
    public String getMessage() {
        // Implementasi custom message InvalidDomainException
        // Return pesan multak berisi: "Email harus memiliki domain yang valid
        return "Email harus memiliki domain yang valid";
    }
}