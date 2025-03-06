import java.util.List;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.stream.*;
import java.util.Collections;

public class parser {
 
}



class simpleParser{



}


class simpleTokenizer{


// StringTokenizer(str) has hardcoded delimeters: \t\n\r\f

// String tokenization

    public List<String> getTokens(String str){

        List<String> tokens = new ArrayList<>();
        StringTokenizer tokenizer = new StringTokenizer(str, ",");
        while(tokenizer.hasMoreElements()){
            // nextToken("e") breaks the string with the delimeter e
            tokens.add(tokenizer.nextToken("e"));
        }
        return tokens;
    }

// String tokenization with streams

    public List<String> getTokenWithCollection (String str){

        return Collections.list(new StringTokenizer(str, ".")).stream()
            .map(token -> (String) token)   
            // type casting b/c StringTokenizer creates an enumeration object 
            .collect(Collectors.toList());
    }



}
