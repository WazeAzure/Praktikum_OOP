import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Solver {
  private ArrayList<String> prompts;

  public Solver() {
    this.prompts = new ArrayList<String>();
  }

  public void addPiece(String prompt) {
    this.prompts.add(prompt);
  }

  public String scrapeAnswer() {
    // Kode berikut masih melakukan scrap ke GPT secara sekuensial.
    // Agar lebih cepat, ubahlah kode di bawah ini menjadi paralel
    // menggunakan wait dan notify, dengan membuat instance Scraper
    // Perhatikan juga bahwa piece answer di sini belum terurut.
    List<Thread> join_group = new ArrayList<>();
    
    String answer = "";

    StringBuilder temp = new StringBuilder();
    
    for (String prompt : prompts) {
        Thread tr = new Scraper(prompt);
        tr.start();
        join_group.add(tr);
    }
    
    for(Thread tr : join_group){
        try {
            tr.join();
        } catch (Exception e){
            
        }
    }
    
    List<Character> ans = new ArrayList<>(Scraper.answer);

    Collections.sort(ans);

    for(Character a : ans){
        temp.append(a);
    }

    answer = temp.toString();

    return answer;
  }
}