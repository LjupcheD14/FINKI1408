package tcp;

import java.io.*;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Random;
import java.util.Scanner;

public class Client extends Thread {

    private int serverPort;
    private String serverName;

    // Constructor to initialize the server port
    public Client(String serverName, int serverPort) {
        this.serverName = serverName;
        this.serverPort = serverPort;
    }

    @Override
    public void run() {
        Socket socket;

        Scanner scanner = null;
        PrintWriter writer = null;

        try{
            socket = new Socket(serverName, serverPort);
            writer = new PrintWriter(socket.getOutputStream());

            scanner = new Scanner(System.in);

            while(true){
                String line = scanner.nextLine();
                writer.println(line);
                writer.flush();
            }
        } catch (UnknownHostException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args) {
        // Create a new Client object with the server port 7000 and start the thread
        Client client = new Client("localhost",7000);
        client.start();
    }
}
