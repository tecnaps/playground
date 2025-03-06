// mvn javadoc:javadoc

package webstuff;

import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;


public class App 
{
/**
 * 
 * A simple port scanner example
 * 
 * @param host can be any host (here: localhost)
 * @param text text to be displayed when a connection is established (port open)
 * 
 */

    public static void main( String[] args )
    {
        String host = "localhost";
        for (int port = 1; port <= 65535; port++){
            try{
                Socket socket = new Socket(host, port);
                String text = "Port " + port + " is open on " + host;
                System.out.println(text);
                socket.close();
            } catch (UnknownHostException e) {
                System.out.println("Server not found:" + e.getMessage());
            } catch (IOException e) {
                // noone is listening here
            }
        }
    }
}
