import java.util.ArrayList;
import java.util.List;

public class Scraper extends Thread {
    private String prompt;
    public static List<Character> answer = new ArrayList<>();

    public Scraper(String pr){
        prompt = pr;
    }
    
    public void run(){
        Gpt g = new Gpt(prompt);

        answer.add(g.getPieceAnswer());

    }
}