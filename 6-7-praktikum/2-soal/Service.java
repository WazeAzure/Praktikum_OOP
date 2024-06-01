import java.util.ArrayList;
import java.util.List;

public class Service {
    private String servicePhone;
    private String serviceName;
    private String serviceEmail;
    private IMessageSender messageSender;
    private List<User> users;


    public Service(String serviceName, String serviceEmail, String servicePhone) {
        // Inisialisasi service dengan serviceName, serviceEmail, dan servicePhone, users diinisialisasi dengan list kosong

        this.serviceEmail = serviceEmail;
        this.serviceName = serviceName;
        this.servicePhone = servicePhone;
        this.users = new ArrayList<User>();
    }

    public void addUser(User user) {
        // Tambahkan user ke dalam list users
        
        this.users.add(user);
    }

    public void sendMessage(String message) {
        // Kirim pesan ke semua user dengan isi pesan message
        // Panggil method sendMessage dari messageSender
        // Cek apakah user memiliki email, jika ada kirim email, dst. Email, device, phone yang kosong tidak perlu dikirim. Data yang kosong ditandai dengan ""
        // Urutan mengirim pesan adalah email, push notif, SMS

        for(User x : this.users){
            if(x.getEmail() != ""){
                this.messageSender = new EmailMessageSender(this.serviceEmail);

                this.messageSender.sendMessage(x, message);
            }

            if(x.getDevice() != ""){
                this.messageSender = new PushNotifMessageSender(this.serviceName);

                this.messageSender.sendMessage(x, message);
            }

            if(x.getPhone() != ""){
                this.messageSender = new SMSMessageSender(this.servicePhone);

                this.messageSender.sendMessage(x, message);
            }
        }
    }
}
