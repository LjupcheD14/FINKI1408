package tcp;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server extends Thread {

    private int port;

    // Constructor to initialize the server with the given port
    public Server(int port) {
        this.port = port;
    }

    @Override
    public void run() {
        System.out.println("SERVER: starting...");
        ServerSocket serverSocket = null;

        try {
            // Create a ServerSocket to listen for incoming connections on the specified port
            serverSocket = new ServerSocket(port);
        } catch (IOException e) {
            System.err.println(e.getMessage());
            return; // Exit if the ServerSocket cannot be created
        }

        System.out.println("SERVER: started");
        System.out.println("SERVER: waiting for connections...");

        while (true) {
            Socket newClient = null;
            try {
                // Accept an incoming client connection and create a new socket for it
                newClient = serverSocket.accept();
                new Worker(newClient).start();
            } catch (IOException e) {
                System.err.println(e.getMessage());
            }
        }
    }

    public static void main(String[] args) {
        // Create a new Server object with the port 7000 and start the thread
        Server server = new Server(7000);
        server.start();
    }
}
