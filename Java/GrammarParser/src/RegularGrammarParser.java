import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class RegularGrammarParser {


/*  Grammar parser for a regular grammar with copilot   */

    private Map<String, String> grammarRules;

    public RegularGrammarParser(){
        grammarRules = new HashMap<>();
    }

    public void addRule(String nonTerminal, String production){
        grammarRules.put(nonTerminal, production);
    }


    public void readGrammarFromFile(String filePath) throws IOException {

        /*  reads grammars from file    */

        try (BufferedReader br = new BufferedReader(new FileReader(filePath))){
            String line;
            while((line = br.readLine()) != null){
                String[] parts = line.split("->");
                if(parts. length == 2){
                    String nonTerminal = parts[0].trim();
                    String production = parts[1].trim();
                    addRule(nonTerminal, production);
                }

            }
        }
    }


    public boolean parse(String input){
        return parse(input, "S");
    }


    private boolean parse(String input, String currentSymbol){

        if(input.isEmpty() && currentSymbol.isEmpty()){
            return true;
        }
        if(input.isEmpty() || currentSymbol.isEmpty()){
            return false;
        }
        
        String production = grammarRules.get(currentSymbol);
        if(production == null){
            return false;
        }

        for (int i = 0; i < production.length(); i++){
            char symbol = production.charAt(i);
            if (Character.isUpperCase(symbol)){
                if (parse(input.substring(1), String.valueOf(symbol))){
                    return true;
                }
            } else if (input.charAt(0) == symbol) {
                return parse(input.substring(1), production.substring(i+1));
            }
        }
        return false;
    }

    public static void main(String[] args){

        /*  main method   */

        /*  with file input */

        RegularGrammarParser parser = new RegularGrammarParser();
        try{
            parser.readGrammarFromFile("ressources/grammar");
        } catch (IOException e){
            e.printStackTrace();
        }

        String input = "ab";
        boolean result = parser.parse(input);
        System.out.println("Input " + input + " is " + (result ? "valid" : "invalid") + " according to the grammar.");

        /*

        without file input

        RegularGrammarParser parser = new RegularGrammarParser();
        parser.addRule("S", "aA");
        parser.addRule("A", "b");

        String input = "ab";
        boolean result = parser.parse(input);
        System.out.println("Input " + input + " is " + (result ? "valid" : "invalid") + " according to the grammar.");
        */
    }
}
