import java.io.File;

public class Driver {
    
    private static boolean lexFlag = false;
    private static boolean parseFlag = false;
    private static boolean codegenFlag = false;
    private static boolean emitAssemblyFlag = false;
    private static String filename;
    protected static int COMPILATION_FINISHED_OK = 0;
    protected static int COMPILATION_FAILED_WITH_ERRORS = -1;

    public static int main(String[] args){

        // assumption about cmd args order: 0) FLAGS 1) PATH

        // case: no flags are passed

        if (args.length==1)
        {
            if (args[0] == null || args[0].trim().isEmpty())
                {
                    System.out.println("Please enter a filename\n");
                    return COMPILATION_FAILED_WITH_ERRORS;
                } else {
                    
                }

        }

        // case: flags are passed

        if (args.length == 2) 
        {
            switch(args[0]){
                case "--lex":   lexFlag = true; 
                                break;
                case "--parse": parseFlag = true;
                                break;
                case "--codegen":   codegenFlag = true;
                                    break;
                case "-S":      emitAssemblyFlag = true;
                                break;
            }
            
            if (args[1] == null  || args[1].trim().isEmpty())
                {
                    System.out.println("Please enter a filename\n");
                    return COMPILATION_FAILED_WITH_ERRORS;
                } else {
                    filename = args[1].trim();
                }

        }

        String path = new File(filename).getAbsolutePath();

        if(lexFlag)
        {
            // --lex flag is set

            // pass 1: run lexer

            return 0;
        }

        else if(parseFlag)
        {
            // --parse flag is set

            // pass 1: run lexer

            // pass 2: run parser

            return 0;
        }

        else if (codegenFlag)
        {
            // --codegen flag is set

            // pass 1: run lexer

            // pass 2: run parser

            // pass 3: run assembler

            return 0;
        }

        else if (emitAssemblyFlag)
        {
            // -S flag is set

            // pass 1: run lexer

            // pass 2: run parser

            // write assembly file
        }

        // no flags

        // pass 1: run lexer

        // Lexer lex = new Lexer(filename);


        // pass 2: run parser

        // pass 3: run assembler

        // pass 4: run code emission

        return COMPILATION_FINISHED_OK;
    }

}
