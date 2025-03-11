import java.io.BufferedReader;
import java.io.FileReader;

public class Lexer {
    
    private BufferedReader in;

    public Lexer(String filename){
        try
        {
            in = new BufferedReader(new FileReader(filename));
        } 
        catch(Exception e)
        {
            System.out.println(filename + " does not exist.");
            return;
        }
    }

    // String tokenization

}
