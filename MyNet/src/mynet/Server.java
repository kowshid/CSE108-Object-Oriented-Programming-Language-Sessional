package mynet;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) {
        try {
            ServerSocket serverSocket=new ServerSocket(33333);
            
            Socket clientSocket=serverSocket.accept();
            
            while(true);
        } catch (IOException e) {
            System.out.println(e);
        }        
    }
}