package webstuff;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

// Threadding
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

//Logging
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;


/**
 * a simple portlistener example
 * 
 * the server is listening on port 8080 for a single client
 * 
 * implemented improvements:
 *
 *  -multiple clients 
 *      (spawning threads) 
 *  -Logging
 *     (use a logging framework like log4j or slf4j)
 * 
 * improvementes: 
 * 
 *  -try with ressources / finally 
 *      (Reader, Writer and Socket may not be closed if an error occurs)
 *  -better error handling
 *      (catch specific exceptions and handle them individually) 
 *  - configurable port
 * 
 *  
 * @param serverSocket server is listening on port 8080
 * 
 */

public class portlistener 
{

    private static final Logger logger = LogManager.getLogger(portlistener.class);
    public static void main( String[] args )
    {
        ExecutorService executorService = Executors.newFixedThreadPool(10);
        try(ServerSocket serverSocket = new ServerSocket(8080)){
            logger.info("Listening on port 8080");
            while(true){
                Socket clientSocket = serverSocket.accept();
                executorService.execute(() -> handleClient(clientSocket));
                } 
        } catch (Exception e) {
            logger.error("Error: " +e);
        }
    }

    private static void handleClient(Socket clientSocket){

        try (BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            PrintWriter out = new PrintWriter(clientSocket.getOutputStream())){
                String inputLine;
                while ((inputLine = in.readLine()) != null){
                    logger.info("Received: "+inputLine);
                    out.println("Message received");
                    if(inputLine.equals("quit"))
                        break;
                }
        } catch (Exception e) {
            logger.error("Error: " + e);
        } finally{
            try{
                clientSocket.close();
            } catch (Exception e) {
                logger.error("Error closing client socket: " + e);
            }
        }
    }
}
